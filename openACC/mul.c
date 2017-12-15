#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

#define N 100000

int main()
{
	int i;int j,tid;
	double a[N],b[N];
	double c=0.0;
	srand(time(NULL));                  //随机函数      
	for(i=0;i<N;i++)
		a[i]=rand()%1000000/1000.0; //产生各个随机数 
	for(j=0;j<N;j++)
		b[j]=rand()%1000000/1000.0; //产生各个随机数 　

	#pragma omp parallel for reduction(+:c)
	for(i=0;i<N;i++)
	{
		c +=a[i]*b[i]*2.0f;
	}
	printf("mp 100000 multiply vector result is:%lf\n",c);
}
