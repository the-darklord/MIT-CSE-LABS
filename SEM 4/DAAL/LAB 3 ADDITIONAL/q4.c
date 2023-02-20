#include <stdio.h>

void read(int M[][100],int m,int n)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&M[i][j]);
        }
    }
}

void display(int M[][100],int m,int n)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",M[i][j]);
        }
        printf("\n");
    }
}

void multiply(int A[][100],int r1,int c1,int B[][100],int c2,int C[][100],int *opc)
{
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c2;j++)
        {
            C[i][j]=0;
            for(int k=0;k<c1;k++)
            {
                (*opc)++;
                C[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
}

void main()
{
    int r1,r2,c1,c2,opc=0;
    printf("Enter Dimensions of Matrix 1 : \t");
    scanf("%d %d",&r1,&c1);
    printf("Enter Dimensions of Matrix 2 : \t");
    scanf("%d %d",&r2,&c2);
    int A[r1][c1],B[r2][c2],C[r1][c2];
    if(c1!=r2)
    {
        printf("Can't Multiply !!\n");
    }
    else
    {
        printf("Enter Matrix 1 Elements : \n");
        read(A,r1,c1);
        printf("\nEnter Matrix 2 Elements : \n");
        read(B,r2,c2);
        printf("\nMatrix 1 :\n");
        display(A,r1,c1);
        printf("\nMatrix 2 :\n");
        display(B,r2,c2);
        multiply(A,r1,c1,B,c2,C,&opc);
        printf("\nResulatant Matrix :\n");
        display(C,r1,c2);
        printf("\nOPCOUNT is %d\n",opc);
    }
}