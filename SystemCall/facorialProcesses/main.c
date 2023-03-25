#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define PROCESS_COUNT 3

int getMultiplication(int _number, const int _start, const int _end){
	int _localMultiplication = 1;
	for(size_t i = _start + 1; i < _end + 1; ++i){
		_localMultiplication *= i;	
	}
	return _localMultiplication;
}

int main(){
	int n;
	printf("Enter a number: ");
	scanf("%i", &n);
	if(n < 0){
		printf("ERROR: Input non negative value\n");
		exit(0);
	}
	if(n == 0){
		printf("FACTORIAL: 1\n");
		return 0;
	}
	// arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}
	//int arr[n] = {1, 6, 8, 9, 13, 1, 99, 2, 5};
	int pipefd[PROCESS_COUNT][2];
	int arrSize = n;//sizeof(arr)/sizeof(arr[0]);
	int blockCount = PROCESS_COUNT % arrSize != 0 ? arrSize/PROCESS_COUNT + 1 : arrSize/PROCESS_COUNT; //arrSize/PROCESS_COUNT;
	pid_t childPid;

	for(size_t i = 0; i < PROCESS_COUNT; ++i){
		pipe(pipefd[i]);
		childPid = fork();
		if(childPid == 0){
			int localMultiplication = 1;
			int startIndx = i * blockCount;
			int endIndx = startIndx + blockCount;
			if(endIndx > arrSize){
				endIndx = arrSize;
			}
			localMultiplication = getMultiplication(n, startIndx, endIndx);
			write(pipefd[i][1], &localMultiplication, sizeof(localMultiplication));
			close(pipefd[i][1]);
			exit(0);
		}
	}
	
	int factorial = 1;
	for(size_t i = 0; i < PROCESS_COUNT; ++i){
		wait(NULL);
		int currentMultiplication;
		read(pipefd[i][0], &currentMultiplication, sizeof(currentMultiplication));
		factorial *= currentMultiplication;
		close(pipefd[i][0]);
	}
	printf("FACTORIAL: %i\n", factorial);

	return 0;
}
