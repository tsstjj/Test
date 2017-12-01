#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#define N 100000
int main()
{
int i;int j,tid;
double a[N],b[N];
srand(time(NULL));
#pragma omp parallel for
for(i=0;i<N;i++)
a[i]=rand()%1000/1.0; //产生各个随机数 
#pragma omp parallel for
for(j=0;j<N;j++)
b[j]=rand()%1000/1.0; //产生各个随机数 　
#pragma omp parallel for
for(i=0;i<N;i++)
{
tid = omp_get_thread_num();
printf("mul=%f tid = %d\n",a[i]*b[i],tid);
}}
