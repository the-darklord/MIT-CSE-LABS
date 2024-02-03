__kernel void copy(__global char *A,__global char *B)
{
    int i = get_global_id(0);
    if(A[i]=='0')
    {
        B[i]='1';
    }
    else
    {
        B[i]='0';
    }
}