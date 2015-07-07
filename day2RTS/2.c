#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREADS 2
int control=1;

void *plus(void *num)
{
	int i=0;  
	long t_num;
	t_num= (long) num;
	pthread_t in;
	in = pthread_self();
	printf("Thread num: %ld thr_IN %ld\n", t_num, in);
	if (t_num==0){
	i=i+10;
	printf("Iplus= %d\n",i);
	}
	else
	{
		i=i-10;
		printf("Iminus= %d\n",i);
	}
}


int main(int argc, char *argv[])
{
	pthread_t threads[NUM_THREADS];
	int rc;
	int rc2;
	long t;
	
	//printf("In main: creating thread %ld\n", t);
	//sleep(10);

	for (t=0; t<2; t++)
	{
	rc= pthread_create(&threads[t], NULL, plus, (void *)t);
	if (rc)
		{
			printf("ERROR; thread number  %d\n", rc);
			exit(-1);
		}
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