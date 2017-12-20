#include <stdio.h>
#include "mpi.h"
main(int argc, char *argv[] )
{
MPI_Init( &argc, &argv );
printf( "高性能并行计算\thello\n" );
MPI_Finalize();
}
