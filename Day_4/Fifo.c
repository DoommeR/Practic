#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define FIFO_FILE       "MYFIFO"

int main(int argc, char *argv[])
{
    FILE *fp;
	int ex;
	
    if ( argc != 2 ) {
        printf("USAGE: fifoclient [string]\n");
        exit(1);
    }

    if((fp = fopen(FIFO_FILE, "w")) == NULL) {
        perror("fopen");
        exit(1);
    }
	
	freopen(FIFO_FILE, "w", stdout);
	ex = execl("/bin/ls","ls", "-l", "/tmp/", NULL);
	//fputs(STDOUT_FILENO, fp);
    fwrite(stdout,sizeof(char), 800,fp);
    fclose(fp);
    return(0);
}