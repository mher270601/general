#include <stdio.h> // printf() / scanf() / sprint() ...
#include <dirent.h> // opend() / closedir() / readdir()
#include <stdlib.h> // exit() / strerror() ...
#include <sys/types.h> // DIR / dirent / mode_t ...
#include <errno.h> // errno
#include <string.h> // strerror

void ls(char* dir_name){
	DIR* dir;
	struct dirent* dir_entry;

	dir = opendir(dir_name);
	
	if(dir == NULL){
		printf("ERROR: %s: %s\n", dir_name, strerror(errno));
		exit(1); // system error
	}

	while((dir_entry = readdir(dir)) != NULL){
		if(strcmp(dir_entry->d_name, ".") == 0 || strcmp(dir_entry->d_name, "..") == 0){
			continue;
		}
		if(dir_entry->d_name[0] == '0'){
			continue;
		}
		printf("%s ", dir_entry->d_name);
	}

	printf("\n");
}
 // sudo cp a /usr/local/bin/
int main(int argc, char* argv[]){

	if(argc < 2){
		ls(".");
		//printf("Invalid command options\n");
		exit(0); // error by user
	}
	
	for(int i = 1; i < argc; ++i){
		printf("%s:\n", argv[i]);
		ls(argv[i]);
		printf("\n");
	}

	//ls(argv[1]);

	return 0;
}
