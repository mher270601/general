#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
	
	if(argc != 2){ // Check command validation
		printf("Invalid command options provided\n");
		exit(-1);
	}
	
	if(access(argv[1], F_OK) != 0){ // Check is file exist
		printf("cannot stat '%s': No such file or directory\n", argv[1]);
		exit(-1);
	}
	int source_fd = open(argv[1], O_RDONLY);
	
	if(source_fd < 0){ // Check if file can open with readOnly mode
		printf("%s: Permission denied\n", argv[1]);
		exit(-1);
	}
	
	char buff[1];

	int sizeOfBuff = 0;
	
	while((sizeOfBuff = read(source_fd, buff, 1)) > 0){
		printf("%s", buff);
	}

	return 0;
}
