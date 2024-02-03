__kernel void copy(__global int *A,__global int *B)
{
    int i = get_global_id(0);
    int n = A[i];
    int temp,sum=0;
    int pow = 1;
    while(n!=0)
    {
        temp = n%10;
        n /= 10;
        sum += temp*pow;
        pow *= 2;
    }
    B[i] = sum;
}