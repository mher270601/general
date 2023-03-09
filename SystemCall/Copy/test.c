#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
	if(argc != 3){
		printf("Invalid command options provided\n");
		exit(-1);
	}

	if(access(argv[1], F_OK) != 0){
		printf("cannot stat '%s': No such file or directory\n", argv[1]);
		exit(-1);
	}
	
	int fd = creat(argv[2], S_IRUSR | S_IWUSR);

	int source_fd = open(argv[1], O_RDONLY);

	if(fd < 0){
		print("%s File not created\n", argv[2]);
		exit(-1);
	}

	char buff[1];

	int sizeOfBuff = 0;

	while((sizeOfBuff = read(source_fd, buff, 1)) > 0){
		write(fd, buff, sizeOfBuff);
	}

	return 0;
}
