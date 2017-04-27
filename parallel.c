#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#define size 100000000
int array[size];
int numThreads;
long sum;
pthread_mutex_t mutex;

void computeSum(void* rank)
{
	int i;
	int start = (int) ((long) rank);
	int division = size / numThreads;
	long localSum = 0;

	for(i = start * division ; i < (start * division) + division ; i++)
	{
		// pthread_mutex_lock(&mutex);
		localSum += array[i];
		// pthread_mutex_unlock(&mutex);
	}

	pthread_mutex_lock(&mutex);
	sum += localSum;
	pthread_mutex_unlock(&mutex);
}

int main()
{
	int i, t;
	pthread_t* threads;
	numThreads = 10;
	sum = 0;

	/* Initialize array with integer values */
	for(i = 0 ; i < 100000000 ; i++)
		array[i] = i % 7;

	/* Initialize threads and lock */
	pthread_mutex_init(&mutex, NULL);
	threads = malloc(numThreads * sizeof(pthread_t));

	/* Compute the sum */
	for(t = 0 ; t < numThreads ; t++)
		pthread_create(&threads[t], NULL, computeSum, (void*) t);

	for(t = 0 ; t < numThreads ; t++)
		pthread_join(threads[t], NULL);


	printf("Sum of the array is: %d\n",sum);

	/* Free memory resources */
	pthread_mutex_destroy(&mutex);
	free(threads);

	return 0;
}