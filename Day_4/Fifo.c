#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h> 
#include <sys/types.h> 

#define SERVER_FIFO_NAME "/tmp/sfifo"
//#define CLIENT_FIFO_NAME "/tmp/cfifo"

int main(int argc, char *argv[])
{
    
	int ex, fd;
	
	if((fd = open(SERVER_FIFO_NAME, O_WRONLY)) < 0) 
	{
	        perror("fopen");
	        exit(1);
	}
	ex = execl("/bin/ls","ls", "-l", "/tmp/", NULL);
	freopen(SERVER_FIFO_NAME, "w", stdout);
	
	close(fd);
	return(0);
}
