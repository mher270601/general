#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
//#include <cassert>

int main(int argc, char* argv[]){
	if(argc < 3){
		perror("ERROR: Invalid count of arguments\n");
		exit(0);
	}
	
	DIR* dir;
	struct dirent* dir_entry;

	dir = opendir(argv[1]);
	if(dir == NULL){
		printf("ERROR: %s\n", strerror(errno));
		exit(1);
	}
	char* _path = malloc(strlen(argv[1]));
	strcat(_path, argv[1]);
	
	while((dir_entry = readdir(dir)) != NULL){
		for(size_t i = 2; i < argc; ++i){
			if(!strcmp(dir_entry->d_name, argv[i])){
				size_t done = 0;
				printf("%s has founded\n", argv[i]);
				char* _dirFile = malloc(strlen(_path) + strlen(argv[i]));
				strcpy(_dirFile, _path);
				if(_dirFile[strlen(_dirFile)-1] != '/'){
					printf("IF CONDITION\n");
					strcat(_dirFile, "/");
				}
				strcat(_dirFile, dir_entry->d_name);
				
				int source_fd1 = open(argv[i], O_RDONLY);
				int source_fd2 = open(_dirFile, O_RDONLY);
				if(source_fd1 < 0){ // Check if file can open with readOnly mode
					printf("%s: Of current file permission denied\n", argv[i]);
					exit(-1);
				}
				if(source_fd2 < 0){ // Check if file can open with readOnly mode
					printf("%s: Of direct file permission denied \n", _dirFile);
					exit(-1);
				}
				char buff1[1], buff2[1];
				int sizeOfBuff1 = 0, sizeOfBuff2 = 0;
				while((sizeOfBuff1 = read(source_fd1, buff1, 1)) > 0 || (sizeOfBuff2 = read(source_fd2, buff2, 1)) > 0){
					if(buff1[0] != buff2[0]){
						printf("Files is not the same\n");
						done = 1;
						break;
					}
				}
				free(_dirFile);
				if(done){
					break;
				}
				printf("Source of %s files is the same\n", dir_entry->d_name);
			}
		}
	}
	free(_path);
	return 0;
}
