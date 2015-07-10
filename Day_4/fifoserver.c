#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

#include <linux/stat.h>

#define FIFO_FILE       "MYFIFO"

int main(void)
{
        FILE *fp;
        char readbuf[800];
        /* Create the FIFO if it does not exist */
        umask(0);
        mknod(FIFO_FILE, S_IFIFO|0666, 0);

        while(1)
        {
                fp = fopen(FIFO_FILE, "r");
				fread(readbuf, sizeof(char), 800, fp);
                //fgets(readbuf, 800, fp);
                printf("Received string: %s\n", readbuf);
                fclose(fp);
        }

        return(0);
}