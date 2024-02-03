__kernel void copy(__global int *A)
{
    int i = get_global_id(0);
    if(i%2==0)
    {
        int temp = A[i+1];
        A[i+1] = A[i];
        A[i] = temp;
    }
}