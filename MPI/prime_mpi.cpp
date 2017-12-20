#include <iostream>
#include <stdio.h>
//#include <mpi.h>

int main(int argc, char* argv[])
{

    int a = 2;
    int z = 100000;
    const int num = z - a + 1;
    int j = 0;
    int p[num];
    int count = 0;
   /* int p_num;
    int id_num;
    /*MPI_Status status;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &id_num);
    MPI_Comm_size(MPI_COMM_WORLD, &p_num);*/
p[0]=p[1]=0;
    for(int i = a; i <= z; i++)
    {
  //      if(i % p_num != id_num)
 //       {
  //          p[i] = 0;
   //         continue;
        //}
        int n = 0;
        for(int j = 2; j <= i; j++)
        {
            if(i % j == 0)
                n ++;
            
        }
        if(n == 1)
            p[i] = i,
            count++;
    }
  /*      else
            p[i] = 0;
    }
    /*if(id_num != 0)
        MPI_Send(p, num, MPI_INT, 0, 99, MPI_COMM_WORLD);
*/
    /*if(id_num == 0){*/
        FILE *fp = NULL;
        fp = fopen("3_mpi.txt", "w");
  
        for(int j = 0;j<count;j++)
                {
             fprintf(fp, "%d\n", p[j]);
                    }
                
            
            /*else{
                for(int i = 0; i < num; i++){
                    if(p[i] != 0){
                        count ++;
                        fprintf(fp, "%d\n", p[i]);
                    }*/
                
            

        
        fclose(fp);
        printf("the number of pe number is : %d\n",count);
    

return 0;
