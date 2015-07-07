#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREADS 2
int control=1;

void *plus(void *num)
{
	control++;
	printf("Control+ = %d\n", control);
}

void *minus(void *num)
{
	control--;
	printf("Control- = %d\n", control);
}

int main(int argc, char *argv[])
{
	pthread_t threads[NUM_THREADS];
	int rc;
	int rc2;
	long t;
	
	//printf("In main: creating thread %ld\n", t);
	//sleep(10);

	
	rc= pthread_create(&threads[0], NULL, plus, (void *)t);
	if (rc)
		{
			printf("ERROR; thread number  %d\n", rc);
			exit(-1);
		}
	rc2= pthread_create(&threads[1], NULL, minus, (void *)t);
	if (rc)
		{
			printf("ERROR; thread number  %d\n", rc);
			exit(-1);
		}

	//pthread_t pthread_self(rc);
	//printf("Number: %d\n", rc);
	

	for (t=0; t< NUM_THREADS; t++)
	{

		pthread_join(threads[t], NULL);
		//printf("thread #%ld finished\n",t);
	}

	return 0;
}