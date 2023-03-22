#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

#define COUNT_OF_BLOCKS 3
#define BLOCK_SIZE 4

int calculateSum(int arr[], int arrSize){
    int _sum = 0;
    for(size_t i = 0; i < arrSize; ++i){
        _sum += arr[i];
    }
    return _sum;
}

int main(int argc, char* argv[]){
    int arr[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 15, 18, 0};
    int sum = 0, child_index = 0;

    for(size_t i = 0; i < COUNT_OF_BLOCKS; ++i){
        pid_t pid = fork();
        if(pid == 0){
            int block[BLOCK_SIZE];
            int startIndex = child_index * BLOCK_SIZE;
            for(size_t j = 0; j < BLOCK_SIZE; ++j){
                block[j] = arr[startIndex + j];
            }
            int blockSum = calculateSum(block, BLOCK_SIZE);
            return blockSum;
        }
        else if(pid > 0){
            ++child_index;
        }
        else{
            printf("ERROR: Unable to fork process %s\n", strerror(errno));
        }
    }
    for(size_t i = 0; i < COUNT_OF_BLOCKS; ++i){
        int childStatus;
        wait(&childStatus);
        if(WIFEXITED(childStatus)){
            sum += WEXITSTATUS(childStatus);
        }
    }
    printf("Total sum: %i\n", sum);
}