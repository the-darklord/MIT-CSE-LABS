#include <stdio.h>
#include <stdlib.h>
void *read(int *h,int r,int c)
{
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",(h + i*r + j));
        }
    }
}
void *display(int *h,int r,int c)
{
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d \t",*(h + i*c + j));
        }
        printf("\n");
    }
}
void *Multiply(int *h,int *g,int *f,int r1,int c1,int c2)
{
    int i,j,k;
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c2;j++)
        {
            *(f + i*r1 + j)=0;
            for(k=0;k<c1;k++)
            {
                *(f + i*r1 + j)=*(f + i*r1 + j) + (*(h + i*r1 + k))*(*(g + k*r1 + j));
            }
        }
    }
}

int main()
{
    int m,n,p,q;
    printf("Enter rows and columns for Matrix A : \t ");
    scanf("%d %d",&m,&n);
    printf("Enter rows and columns for Matrix B : \t ");
    scanf("%d %d",&p,&q);
    int *a=(int*)malloc(m*n*sizeof(int));
    int *b=(int*)malloc(p*q*sizeof(int));
    int *c=(int*)malloc(m*q*sizeof(int));
    printf("Enter Matrix A \n");
    read(a,m,n);
    printf("Enter Matrix B \n");
    read(b,p,q);
    printf("Matrix A \n");
    display(a,m,n);
    printf("Matrix B \n");
    display(b,p,q);
    if(n==p)
    {
        printf("Matrix after Multiplication is \n");
        Multiply(a,b,c,m,n,q);
        display(c,m,q);
    }
    else
    {
        printf("Matrices can't be Multiplied");
    }
    return 0;
}