#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char toggle(char c)
{
    if(c>='A'&&c<='Z')
    {
        c += 32;
    }
    else if(c>='a'&&c<='z')
    {
        c -= 32;
    }
    return c;
}

int main(int argc,char* argv[])
{
    int rank,size;
    char str[100];
    strcpy(str,argv[1]);
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    str[rank] = toggle(str[rank]);
    printf("Rank : %d , toggled : %s\n",rank,str);
    MPI_Finalize();
    return 0;
}