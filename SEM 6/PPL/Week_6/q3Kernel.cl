__kernel void odd(__global int* A,int N)
{
    int i = get_global_id(0);
    int pos = 0;
    if((i%2)!=0 && i<N-1)
    {
        if(A[i]>A[i+1])
        {
            int temp = A[i];
            A[i] = A[i+1];
            A[i+1] = temp;
        }
    }
}

__kernel void even(__global int* A,int N)
{
    int i = get_global_id(0);
    int pos = 0;
    if((i%2)==0 && i<N-1)
    {
        if(A[i]>A[i+1])
        {
            int temp = A[i];
            A[i] = A[i+1];
            A[i+1] = temp;
        }
    }
}