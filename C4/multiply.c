#include<stdio.h> 
int p,q,k; 
void main(){
	float A[2][2]={1.5,1.5,2.4,1.3},B[2][1]={2.8,1.6};
	float C[2][1]={0};
	printf("矩阵A*矩阵B为:\n"); //计算两个矩阵相乘；以[2][2]*[2][1]为例
	for(p=0;p<2;++p)  
    {
        for(q=0;q<1;++q)
        {
            for(k=0;k<2;++k)
                C[p][q]+=A[p][k]*B[k][q];
        }
    }
	for(p=0;p<2;p++) {
		for(q=0;q<1;q++) 
		{ 
			printf("%f",C[p][q]); 
				printf("\n"); 
		} 
	}
}
