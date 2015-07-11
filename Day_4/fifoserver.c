#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h> 
#include <sys/types.h> 
#include <linux/stat.h>
#include <fcntl.h>

#define SERVER_FIFO_NAME "/tmp/sfifo"

int main(void)
{
	int fd;
        char readbuf[800];
        /* Create the FIFO if it does not exist */
        umask(0);
        mknod(SERVER_FIFO_NAME, S_IFIFO|0666, 0);

        while(1)
        {
                fd = open(SERVER_FIFO_NAME, O_RDONLY);
		read(fd, &readbuf, sizeof(readbuf));
                //fgets(readbuf, 800, fp);
                printf("Received string: %s\n", readbuf);
                close(fd);
        }

        return(0);
}
