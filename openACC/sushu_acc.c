#include <stdio.h>
#include <stdlib.h>
#define N 100000

int prime(int num)
{
	int i=0;
	int j=0;
	int output[N];
	int flag =0; 
	int count = 0 ; 
	char inputchar = 0;
	FILE *fp;
	fp = fopen("sushu_acc.txt","w");
	#pragma acc kernels
	{
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
				output[count] = i;

		
			}		
		}
	}
	for(i=0;i<count;i++)
		fprintf(fp,"%d\n",output[i]);

	fclose(fp);
	return count;
}

void main()
{
	int num=0,thread_num =8;
	
	num = prime(thread_num);
	printf("acc output sum: %d\nthread num:%d",num,thread_num);
}
