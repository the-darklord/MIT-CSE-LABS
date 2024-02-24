#include <stdio.h>
#include<time.h>
#include <CL/cl.h>
#include<string.h>
#include<stdlib.h>
#define MAX_SOURCE_SIZE (0x100000)
int main(void){
	int n;
	char str[100];
	int i;
	printf("Enter number of words: ");
	scanf("%d",&n);
	int startoff[n+1];
	startoff[0] = 0;
	for(i=0;i<n;i++){
		char temp[20];
		printf("Enter word %d: ",i+1);
		scanf("%s",temp);
		strcat(str,temp);
		startoff[i+1] = startoff[i] + strlen(temp);
	}
	int len = strlen(str);
	
	char *source_str = "__kernel void revWords (__global char *A,__global int* C){int i = get_global_id(0); int len = C[i+1]-C[i]; for(int j=0;j<len/2;j++){ char temp = A[j+C[i]]; A[j+C[i]] = A[len-j+C[i]-1]; A[len-j+C[i]-1]=temp;}}";
	size_t source_size = strlen(source_str);

	cl_platform_id platform_id = NULL;
	cl_device_id device_id = NULL;
	cl_uint ret_num_devices;
	cl_uint ret_num_platforms;

	cl_int ret = clGetPlatformIDs(1, &platform_id, &ret_num_platforms);
	ret = clGetDeviceIDs( platform_id, CL_DEVICE_TYPE_GPU, 1,&device_id,&ret_num_devices);

	cl_context context = clCreateContext( NULL, 1, &device_id, NULL, NULL, &ret);
	cl_command_queue command_queue = clCreateCommandQueue(context,device_id, NULL, &ret);
	cl_mem s_mem_obj = clCreateBuffer(context, CL_MEM_READ_WRITE,len*sizeof(char), NULL, &ret);
	cl_mem st_mem_obj = clCreateBuffer(context, CL_MEM_READ_ONLY,(n+1)*sizeof(int), NULL, &ret);
	ret = clEnqueueWriteBuffer(command_queue, s_mem_obj, CL_TRUE, 0,len *sizeof(char), str, 0, NULL, NULL);
	ret = clEnqueueWriteBuffer(command_queue, st_mem_obj, CL_TRUE, 0,(n+1)*sizeof(int), startoff, 0, NULL, NULL);
	cl_program program = clCreateProgramWithSource(context, 1,(const char**)&source_str, (const size_t *)&source_size, &ret);
	ret = clBuildProgram(program, 1, &device_id, NULL, NULL, NULL);
	
	cl_kernel kernel = clCreateKernel(program, "revWords", &ret);

	ret = clSetKernelArg(kernel, 0, sizeof(cl_mem), (void *)&s_mem_obj);
	ret = clSetKernelArg(kernel, 1, sizeof(cl_mem), (void *)&st_mem_obj);
	
	size_t global_item_size = n;
	size_t local_item_size = 1;

	cl_event event;
	ret = clEnqueueNDRangeKernel(command_queue, kernel, 1, NULL,&global_item_size, &local_item_size, 0, NULL, &event);
	
	ret = clFinish(command_queue);

	char *strres = (char*)malloc(sizeof(char)*len);
	ret = clEnqueueReadBuffer(command_queue, s_mem_obj, CL_TRUE, 0,len*sizeof(char), strres, 0, NULL, NULL);
	strres[(n*len)]='\0';
	for(int i=0;i<n;i++){
		int index = startoff[i];
		while(index<startoff[i+1]){
			printf("%c",strres[index]);
			index++;
		}
		printf(" ");
	}
    printf("\n");
	ret = clReleaseKernel(kernel);
	ret = clReleaseProgram(program);
	ret = clReleaseMemObject(s_mem_obj);
	ret = clReleaseMemObject(st_mem_obj);
	ret = clReleaseCommandQueue(command_queue);
	ret = clReleaseContext(context);
	free(strres);
	return 0;
}
