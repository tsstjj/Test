#include<stdio.h>
#define N 100000

int prime()
{
	int i=0;
	int j=0;
	int flag =0; 
	int count = 0 ; 
	char inputchar = 0;
	FILE *fp;
	fp = fopen("sushu.txt","w");
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
	int num=0;
	
	num = prime();
	printf("output sum: %d\n",num);
}
