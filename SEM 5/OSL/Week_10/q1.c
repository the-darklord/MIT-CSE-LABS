#include <stdio.h>
#include <stdlib.h>

void printMat(int** arr,int r,int c)
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}

void printArr(int* arr,int r)
{
    for(int i=0;i<r;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void Bankers(int** alloc,int** max,int** need,int* avail,int pro,int res)
{
    int finish[pro],answer[pro],ind=0;
    for(int i=0;i<pro;i++)
    {
        finish[i]=0;
    }
    for(int i=0;i<pro;i++)
    {
        for(int j=0;j<pro;j++)
        {
            if(finish[j]==0)
            {
                int flag=0;
                for(int l=0;l<res;l++)
                {
                    if(need[j][l]>avail[l])
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                {
                    answer[ind++]=j;
                    for(int k=0;k<res;k++)
                    {
                        avail[k] += alloc[j][k];
                    }
                    finish[j]=1;
                }
            }
        }
    }
    int flag=1;
    for(int i=0;i<pro;i++)
    {
        if(finish[i]==0)
        {
            flag=0;
            printf("The Following System is Unsafe!!!\n");
            break;
        }
    }
    if(flag==1)
    {
        printf("Following is the Safe Sequence for the given System\n");
        for(int i=0;i<pro-1;i++)
        {
            printf("P%d -> ",answer[i]);
        }
        printf("P%d\n",answer[pro-1]);
    }
    exit(EXIT_SUCCESS);
}

void main()
{
    int n_res,n_pro;
    printf("Enter No. of Processes : \t");
    scanf("%d",&n_pro);
    printf("\nEnter No. of Resources : \t");
    scanf("%d",&n_res);
    int* claim;
    claim=(int*)calloc(n_res,sizeof(int));
    printf("\nEnter Claim Vector : \n");
    for(int i=0;i<n_res;i++)
    {
        scanf("%d",&claim[i]);
    }
    int** alloc;
    alloc=(int**)calloc(n_pro,sizeof(int*));
    printf("\nEnter Allocation Matrix : \n");
    for(int i=0;i<n_pro;i++)
    {
        alloc[i]=(int*)calloc(n_res,sizeof(int));
        printf("Enter Allocation Data for Process %d : \n",i+1);
        for(int j=0;j<n_res;j++)
        {
            scanf("%d",&alloc[i][j]);
        }
    }
    int** max;
    max=(int**)calloc(n_pro,sizeof(int*));
    int** need;
    need=(int**)calloc(n_pro,sizeof(int*));
    printf("\nEnter Max. Matrix : \n");
    for(int i=0;i<n_pro;i++)
    {
        max[i]=(int*)calloc(n_res,sizeof(int));
        need[i]=(int*)calloc(n_res,sizeof(int));
        printf("Enter Max. Data for Process %d : \n",i+1);
        for(int j=0;j<n_res;j++)
        {
            scanf("%d",&max[i][j]);
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    int* avail;
    avail=(int*)calloc(n_res,sizeof(int));
    for(int i=0;i<n_res;i++)
    {
        avail[i]=0;
        for(int j=0;j<n_pro;j++)
        {
            avail[i] += alloc[j][i];
        }
        avail[i]=claim[i]-avail[i];
        if(avail[i]<0)
        {
            perror("Incorrect Data Entered !!!\n");
            exit(EXIT_FAILURE);
        }
    }
    printf("\nClaim Vector\n");
    printArr(claim,n_res);
    printf("\nAllocation\n");
    printMat(alloc,n_pro,n_res);
    printf("\nMax\n");
    printMat(max,n_pro,n_res);
    printf("\nNeed\n");
    printMat(need,n_pro,n_res);
    printf("\nAvailable Vector\n");
    printArr(avail,n_res);
    Bankers(alloc,max,need,avail,n_pro,n_res);
}