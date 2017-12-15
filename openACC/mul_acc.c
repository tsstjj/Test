#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define N 100000

int main()
{
	float *restrict a;  /* the vector */
        float *restrict b;  /* the results */

	int i;int j,tid;
	float mul =0.0;

        a = (float*)malloc(N*sizeof(float));
        b = (float*)malloc(N*sizeof(float));

	srand(time(NULL));
	for(i=0;i<N;i++)
		a[i]=rand()%1000/1.0; //产生各个随机数 
	for(j=0;j<N;j++)
		b[j]=rand()%1000/1.0; //产生各个随机数 　
	#pragma acc region
	{
		for(i=0;i<N;i++)
		{
			mul+=a[i]*b[i]*2.0f;

		}
	}

	printf("acc 100000 multiply vector result is:%lf\n",mul);
}
