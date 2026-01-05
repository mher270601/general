#include <windows.h>
#include <tchar.h>
#include <strsafe.h>
#include "core/MonitorManager.hpp"

SERVICE_STATUS          g_ServiceStatus = {0};
SERVICE_STATUS_HANDLE   g_StatusHandle = NULL;
HANDLE                  g_ServiceStopEvent = INVALID_HANDLE_VALUE;

MonitorManager          g_MonitorManager;

VOID WINAPI ServiceMain(DWORD argc, LPTSTR *argv);
VOID WINAPI ServiceCtrlHandler(DWORD);
DWORD WINAPI ServiceWorkerThread(LPVOID lpParam);

#define SERVICE_NAME  TEXT("AppMonitorService")

int main(){
	SERVICE_TABLE_ENTRY ServiceTable[] = {
		{ (LPTSTR)SERVICE_NAME, (LPSERVICE_MAIN_FUNCTION)ServiceMain },
		{ NULL, NULL }
	};

	if(StartServiceCtrlDispatcher(ServiceTable) == FALSE){
		return GetLastError();
	}

	return 0;
}

VOID WINAPI ServiceMain(DWORD argc, LPTSTR *argv){
	DWORD Status = E_FAIL;

	g_StatusHandle = RegisterServiceCtrlHandler(SERVICE_NAME, ServiceCtrlHandler);
	if(g_StatusHandle == NULL){
		return;
	}

	ZeroMemory(&g_ServiceStatus, sizeof(g_ServiceStatus));
	g_ServiceStatus.dwServiceType = SERVICE_WIN32_OWN_PROCESS;
	g_ServiceStatus.dwControlsAccepted = 0;
	g_ServiceStatus.dwCurrentState = SERVICE_START_PENDING;
	g_ServiceStatus.dwWin32ExitCode = 0;
	g_ServiceStatus.dwServiceSpecificExitCode = 0;
	g_ServiceStatus.dwCheckPoint = 0;

	g_ServiceStopEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
	if(g_ServiceStopEvent == NULL){
		g_ServiceStatus.dwCurrentState = SERVICE_STOPPED;
		g_ServiceStatus.dwWin32ExitCode = GetLastError();
		SetServiceStatus(g_StatusHandle, &g_ServiceStatus);
		return;
	}

	g_ServiceStatus.dwControlsAccepted = SERVICE_ACCEPT_STOP;
	g_ServiceStatus.dwCurrentState = SERVICE_RUNNING;
	g_ServiceStatus.dwCheckPoint = 0;
	g_ServiceStatus.dwWaitHint = 0;
	SetServiceStatus(g_StatusHandle, &g_ServiceStatus);

	g_MonitorManager.Initialize();
	g_MonitorManager.StartAll();

	HANDLE hThread = CreateThread(NULL, 0, ServiceWorkerThread, NULL, 0, NULL);
	WaitForSingleObject(hThread, INFINITE);
	CloseHandle(hThread);
	CloseHandle(g_ServiceStopEvent);

	g_MonitorManager.StopAll();

	g_ServiceStatus.dwControlsAccepted = 0;
	g_ServiceStatus.dwCurrentState = SERVICE_STOPPED;
	g_ServiceStatus.dwWin32ExitCode = 0;
	g_ServiceStatus.dwCheckPoint = 3;
	SetServiceStatus(g_StatusHandle, &g_ServiceStatus);
	
	return;
}

VOID WINAPI ServiceCtrlHandler(DWORD CtrlCode){
	switch(CtrlCode){
		case SERVICE_CONTROL_STOP:
			if(g_ServiceStatus.dwCurrentState != SERVICE_RUNNING){
				break;
			}
			g_ServiceStatus.dwControlsAccepted = 0;
			g_ServiceStatus.dwCurrentState = SERVICE_STOP_PENDING;
			g_ServiceStatus.dwWin32ExitCode = 0;
			g_ServiceStatus.dwCheckPoint = 4;
			SetServiceStatus(g_StatusHandle, &g_ServiceStatus);
			SetEvent(g_ServiceStopEvent);
			break;
		default:
			break;
	}
}

DWORD WINAPI ServiceWorkerThread(LPVOID lpParam){
	while(WaitForSingleObject(g_ServiceStopEvent, 0) != WAIT_OBJECT_0){
		Sleep(1000);
	}
	return ERROR_SUCCESS;
}
