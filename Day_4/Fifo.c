#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h> 
#include <sys/types.h> 

#define SERVER_FIFO_NAME "/tmp/sfifo"

int main(int argc, char *argv[])
{
    
	int ex, fd;
	
	if((fd = open(SERVER_FIFO_NAME, O_WRONLY)) < 0) 
	{
	        perror("fopen");
	        exit(1);
	}
	
	freopen(SERVER_FIFO_NAME, "w", stdout);
	ex = execl("/bin/ls","ls", "-l", "/tmp/", NULL);
	close(fd);
	return(0);
}
