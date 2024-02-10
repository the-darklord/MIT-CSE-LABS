__kernel void copy(__global char* A,__global char* B,int len)
{
    int i = get_global_id(0);
    B[i] = A[i%len];
}