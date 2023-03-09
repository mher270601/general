#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
	if(argc < 2){
		printf("Invalid command options provided\n");
		exit(-1);
	}
	for(int i = 0; i < argc; ++i){
		int fd = creat(argv[i], S_IRUSR | S_IXUSR | S_IWUSR);
		if(fd < 0){
			printf("Can't creat file: %s\n", argv[i]);
		}
	}

	return 0;
}
