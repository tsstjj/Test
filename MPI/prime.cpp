#include <iostream>
#include <stdio.h>
#include <mpich/mpi.h>

#define N 100000

int main(int argc, char* argv[])
{

    int a = 2;

    const int num = N - a + 1;

    int p[num];

    int p_num;
    int id_num;
    MPI_Status status;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORfatal error: mpi.hLD, &id_num);
    MPI_Comm_size(MPI_COMM_WORLD, &p_num);

    for(int i = a; i <= N; i++){
        if(i % p_num != id_num)
        {
            p[i] = 0;
            continue;
        }
        int n = 0;
        for(int j = 2; j <= i; j++)
        {
            if(i % j == 0)
                n ++;
            
        }
        if(n == 1)
            p[i] = i;
        else
            p[i] = 0;
    }
    if(id_num != 0)
        MPI_Send(p, num, MPI_INT, 0, 99, MPI_COMM_WORLD);

    if(id_num == 0){
        FILE *fp = NULL;
        fp = fopen("prime_mpi.txt", "w");
        int count = 0;

        int get_p[num];
        for(int source = 0; source < p_num; source++){
            if(source != 0){
                MPI_Recv(get_p, num, MPI_INT, source, 99, MPI_COMM_WORLD,&status);
                for(int i = 0; i < num; i++){
                    if(get_p[i] != 0){
                        count ++;
                        fprintf(fp, "%d\n", get_p[i]);
                    }
                }
            }
            else{
                for(int i = 0; i < num; i++){
                    if(p[i] != 0){
                        count ++;
                        fprintf(fp, "%d\n", p[i]);
                    }
                }
            }

        }
        fclose(fp);
        printf("the total is : %d\n",count++);
    }
    MPI_Finalize();

    return 0;
}
