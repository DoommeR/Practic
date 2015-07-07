#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define NUM_THREADS 2
char password[128]="";
char password_OK[128]="hi";


void *Get_Password(void *num)
{
    int i=0;
    int str;

	printf("enter password: ");
	while ((str = getchar ( )) != '\n') 
		password [i++] = str;
	printf("\n You entered: %s\n", password);
}

void *Recognize_Password(void *num)
{
	if (strcmp (password, password_OK)==0) printf("OK!\n");
	else printf("Incorrect!\n");
}

int main(int argc, char *argv[])
{
	pthread_t threads[NUM_THREADS];
	int rc;
	int rc2;
	long t;
	
	//printf("In main: creating thread %ld\n", t);
	
	rc= pthread_create(&threads[0], NULL, Get_Password, (void *)t);
	if (rc)
		{
			printf("ERROR; thread number  %d\n", rc);
			exit(-1);
		}
	sleep(10);
	rc2= pthread_create(&threads[1], NULL, Recognize_Password, (void *)t);
	if (rc2)
		{
			printf("ERROR; thread number  %d\n", rc);
			exit(-1);
		}

	//pthread_t pthread_self(rc);
	//printf("Number: %d\n", rc);
	

	for (t=0; t< NUM_THREADS; t++)
	{

		pthread_join(threads[t], NULL);
		printf("thread #%ld finished\n",t);
	}

	return 0;
}