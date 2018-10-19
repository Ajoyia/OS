#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
int array[1000]; // Initialize An Array Of 1000 Numbers Globally
void * Thread(void * arg)
{
	int start=(int)arg;	
	int sum=0;
	for (int i=start;i<arg+100;i++)
	{
		sum=sum+array[i];
	}
	return ((void*)sum);
}
int main()
{
	pthread_t thread1,thread2,thread3,thread4,thread5,thread6,thread7,thread8,thread9,thread10;
	int sum1,sum2,sum3,sum4,sum5,sum6,sum7,sum8,sum9,sum10,total;
	for (int i=0;i<1000;i++)
	{
		array[i]=i+1; // Fill The Array's Indexes with numbers
	}
	// Create 10 new threads
	pthread_create(&thread1 ,NULL,Thread,(void*)(0));
	pthread_create(&thread2 ,NULL,Thread,(void*)(100));
	pthread_create(&thread3 ,NULL,Thread,(void*)(200));
	pthread_create(&thread4 ,NULL,Thread,(void*)(300));
	pthread_create(&thread5 ,NULL,Thread,(void*)(400));
	pthread_create(&thread6 ,NULL,Thread,(void*)(500));
	pthread_create(&thread7 ,NULL,Thread,(void*)(600));
	pthread_create(&thread8 ,NULL,Thread,(void*)(700));
	pthread_create(&thread9 ,NULL,Thread,(void*)(800));
	pthread_create(&thread10,NULL,Thread,(void*)(900));
	// Complete the execution of all threads
	pthread_join(thread1,(void **) & sum1); 
	pthread_join(thread2,(void **) & sum2);
	pthread_join(thread3,(void **) & sum3);
	pthread_join(thread4,(void **) & sum4);
	pthread_join(thread5,(void **) & sum5);
	pthread_join(thread6,(void **) & sum6);
	pthread_join(thread7,(void **) & sum7);
	pthread_join(thread8,(void **) & sum8);
	pthread_join(thread9,(void **) & sum9);
	pthread_join(thread10,(void **)& sum10);
	
	total=sum1+sum2+sum3+sum4+sum5+sum6+sum7+sum8+sum9+sum10; // Sum The Values
	
	printf("Sum is : %d\n",total); // Print Total Sum
	return 0;
}
