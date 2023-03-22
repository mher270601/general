#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define PROCESS_COUNT 3

int getSum(int arr[], int _start, int _end){
	int sum = 0;
	for(size_t i = _start; i < _end; ++i){
		sum += arr[i];	
	}
	return sum;
}

int main(){
	int arr[] = {1, 6, 8, 9, 13, 1, 99, 2, 5};
	int pipefd[PROCESS_COUNT][2];
	int arrSize = sizeof(arr)/sizeof(arr[0]);
	int blockCount = PROCESS_COUNT % arrSize != 0 ? arrSize/PROCESS_COUNT + 1 : arrSize/PROCESS_COUNT; //arrSize/PROCESS_COUNT;
	pid_t childPid;

	for(size_t i = 0; i < PROCESS_COUNT; ++i){
		pipe(pipefd[i]);
		childPid = fork();
		if(childPid == 0){
			int sum = 0;
			int startIndx = i * blockCount;
			int endIndx = startIndx + blockCount;
			if(endIndx > arrSize){
				endIndx = arrSize;
			}
			sum = getSum(arr, startIndx, endIndx);
			write(pipefd[i][1], &sum, sizeof(sum));
			close(pipefd[i][1]);
			exit(0);
		}
	}
	
	int totalSum = 0;
	for(size_t i = 0; i < PROCESS_COUNT; ++i){
		wait(NULL);
		int localSum;
		read(pipefd[i][0], &localSum, sizeof(localSum));
		totalSum += localSum;
		close(pipefd[i][0]);
	}
	printf("TOTAL SUM: %i\n", totalSum);

	return 0;
}
