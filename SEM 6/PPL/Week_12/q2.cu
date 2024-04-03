#include "cuda_runtime.h"
#include<stdio.h>
#include "device_launch_parameters.h"

__constant__ float d_N[100];
__constant__ int d_width;
__constant__ float d_M[100];
__constant__ int d_mask_width;

__global__ void convolution_1D(float *P){
	int i = blockIdx.x * blockDim.x + threadIdx.x;
	float Pvalue = 0;
	int N_start_point = i - (d_mask_width/2);
	for(int j=0;j<d_mask_width;j++){
		if(N_start_point+j >=0 && N_start_point+j < d_width){
			Pvalue += d_N[N_start_point+j]*d_M[j];
		}
	}
	P[i] = Pvalue;
}

int main(void) {
	float *N, *M, *P;
	int width,mask_width;
	printf("Enter the width: ");
	scanf("%d",&width);
	printf("Enter the mask width: ");
	scanf("%d",&mask_width);
	N = (float*)malloc(width*sizeof(float));
	M = (float*)malloc(mask_width*sizeof(float));
	P = (float*)malloc(width*sizeof(float));
	float *d_c;
	int size= sizeof(float);
	for(int i=0;i<width;i++){
		N[i] = i+1;
	}
	for(int i=0;i<mask_width;i++){
		M[i] = i+10;
	}

	cudaMalloc((void **)&d_c, width*size);

	cudaMemcpyToSymbol(d_N,N,width*size);
	cudaMemcpyToSymbol(d_M,M,mask_width*size);
	cudaMemcpyToSymbol(d_width,&width,sizeof(int));
	cudaMemcpyToSymbol(d_mask_width,&mask_width,sizeof(int));

	convolution_1D<<<1,width>>>(d_c);

	cudaMemcpy(P, d_c, width*size, cudaMemcpyDeviceToHost);
	printf("Result:\n");
	for(int i=0;i<width;i++){
		printf("%lf ",P[i]);
	}
    printf("\n");
	cudaFree(d_c);
	return 0;
}