__kernel void copy(__global int* A,__global int* B,int N)
{
    int i = get_global_id(0);
    int pos = 0;
    for(int j=i+1;j<N;j++)
    {
        if(A[j]<A[i])
        {
            pos++;
        }
    }
    B[pos] = A[i];
}