#include<stdio.h>
#define N 100000
int prime(int num)
{
	int i=0;
	int j=0;
	int flag =0; 
	int count = 0 ; 
	char inputchar = 0;
	FILE *fp;
	fp = fopen("sushu_omp.txt","w");
	omp_set_num_threads(num);//设置最大线程数
	#pragma omp parallel for private(j) reduction(+:count)
	for(i=2;i<=N;i++)
	{
		flag = 0;
		for(j=2;j<i;j++)
		{
			if(i%j == 0)
			{
				flag = 1;
				break;
			}
			
		}
		if(flag == 0)
		{
			count++;
			fprintf(fp,"%d\n",i);
		}		
	}
	fclose(fp);
	return count;
}

void main()
{
	int num=0,thread_num =8;
	
	num = prime(thread_num);
	printf("mp output sum: %d\nthread num:%d",num,thread_num);
}
