#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREADS 5

void *print_hello(void *num)
{
	long t_num;
	t_num= (long) num;
	pthread_t in;
	in = pthread_self();
	
	
	printf("Thread num: %ld thr_IN %ld\n", t_num, in);
}

int main(int argc, char *argv[])
{
	pthread_t threads[NUM_THREADS];
	int rc;
	long t;
	
	for(t=0; t< NUM_THREADS; t++)
	{
	//printf("In main: creating thread %ld\n", t);
		int i;
	sleep(10);
	rc= pthread_create(&threads[t], NULL, print_hello, (void *)t);
	if (rc)
		{
			printf("ERROR; thread number  %d\n", rc);
			exit(-1);
		}
	//pthread_t pthread_self(rc);
	//printf("Number: %d\n", rc);
	
	}

	for (t=0; t< NUM_THREADS; t++)
	{

		pthread_join(threads[t], NULL);
		//printf("thread #%ld finished\n",t);
	}
//http://habrahabr.ru/post/127278/
	return 0;
}
