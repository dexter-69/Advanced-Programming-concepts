#include<stdio.h>
#include<sys/time.h>

void bubbleSort(int A[], int N);

int main()
{
	struct timeval start, end;
	int A1[8000], A2[16000], i;
	long int time1, time2;
	float ratio;

	for(i=7999; i>=0; --i)
	A1[i]=i;


	for(i=15999; i>=0; --i)
	A2[i]=i;

	gettimeofday(&start, NULL);
	bubbleSort(A1, 8000);
	gettimeofday(&end, NULL);


	time1=(end.tv_sec*1000000+end.tv_usec) - (start.tv_sec*1000000+start.tv_usec);

	gettimeofday(&start, NULL);
	bubbleSort(A2, 16000);
	gettimeofday(&end, NULL);

	time2=(end.tv_sec*1000000+end.tv_usec) - (start.tv_sec*1000000+start.tv_usec);


	ratio= (float)time2/time1;

	printf("After Sorting\
		\n\ntime1 = %ld, time2 = %ld\
		\n\ntime2/time1 = %f", time1, time2, ratio);

}

void bubbleSort(int A[], int N)
{
	int i, j, temp;

        for(i=0; i<N-1; i++)
		for(j=0; j<N-i-1; j++)
			if(A[j]>A[j+1])
			{
				temp=A[j];
				A[j]=A[j+1];
				A[j+1]=temp;
			}
}
