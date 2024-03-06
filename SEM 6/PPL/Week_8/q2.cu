/*
    COPYRIGHT
*/

#include <cuda_runtime.h>
#include <device_launch_parameters.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

__global__ void Copy(char *str, char *rstr,int* ind,int len)
{
    int i = threadIdx.x;
    for(int j=0;j<len-i;j++)
    {
        rstr[ind[i]+j] = str[j];
    }
}

int main()
{
    char str[100],rstr[300];
    printf("Enter a String : \n");
    scanf("%s", str);
    char *d_str,*d_rstr;
    int len = strlen(str);
    int* ind = (int*)malloc(len*sizeof(int));
    int *d_ind;
    ind[0] = 0;
    for(int i=1;i<len;i++)
    {
        ind[i] = ind[i-1]+len-i+1;
    }
    cudaMalloc((void**)&d_str, len * sizeof(char));
    cudaMalloc((void**)&d_rstr, (len*len)*sizeof(char));
    cudaMalloc((void**)&d_ind, len * sizeof(int));
    cudaMemcpy(d_str, str, len * sizeof(char), cudaMemcpyHostToDevice);
    cudaMemcpy(d_ind, ind, len * sizeof(int), cudaMemcpyHostToDevice);
    Copy<<<1,len>>>(d_str,d_rstr,d_ind,len);
    cudaMemcpy(rstr, d_rstr, (len*len)*sizeof(char), cudaMemcpyDeviceToHost);
    printf("\nResultant String : %s\n",rstr);
    cudaFree(d_str);
    cudaFree(d_rstr);
    return 0;
}