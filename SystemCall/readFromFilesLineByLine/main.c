#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("ERROR: Invalid count of arguments");
        exit(1);
    }

    int fd1 = open(argv[1], O_RDONLY);
    if (fd1 < 0) {
        printf("ERROR: In opening %s file", argv[1]);
        exit(1);
    }
    
    int fd2 = open(argv[2], O_RDONLY);
    if (fd2 < 0) {
        printf("ERROR: In opening %s file", argv[2]);
        exit(1);
    }

    int fd3 = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd3 < 0) {
        printf("ERROR: In creating/opening output.txt file");
        exit(1);
    }

    char buffer[1], buffer2[1];
    ssize_t nread, nread2 = 1;
    
    while(nread || nread2){
    	while ((nread = read(fd1, buffer, 1)) > 0) {
    	        if (buffer[0] == '\n') {
    	            write(fd3, buffer, nread);
		    break;
    	        } 
		else {
    	            write(fd3, buffer, nread);
    	        }
    	}
    	while ((nread2 = read(fd2, buffer2, 1)) > 0) {
    	        if (buffer2[0] == '\n') {
    	            write(fd3, buffer2, nread2);
		    break;
    	        } 
		else {
    	            write(fd3, buffer2, nread2);
    	        }
    	}
    }

    close(fd1);
    close(fd2);
    close(fd3);

    return 0;
}
