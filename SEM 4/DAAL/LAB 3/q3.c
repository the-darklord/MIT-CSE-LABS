#include<stdio.h>
#include<stdlib.h>
#include <math.h>

void subsets(int* arr,int n,int des_sum,int* opcount){\
	int n_sets = 0;
	int n_subsets = pow(2,n);
	for(int i=0;i<n_subsets;i++){
		int sum=0,count=0;
		int* sub = (int*)calloc(n,sizeof(int));
		for(int j=0;j<n;j++){
			(*opcount)++;
			if(i & (1 << j)){
				sub[count++] = arr[j];
				sum+=arr[j];
			}
		}
		if(des_sum == sum){
			n_sets++;
			for(int k=0;k<count;k++)
				printf("%d ",sub[k]);
			printf("\n");
			if(n_sets == 2)
				return;
		}
	}
}

int main(){
	int n,opcount=0;
	printf("Enter the value of n: ");
	scanf("%d",&n);
	int* arr = (int*)malloc(n*sizeof(int));
	printf("Enter the elements: ");
	int sum=0;
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
		sum+=arr[i];
	}
	subsets(arr,n,sum/2,&opcount);
	printf("Operation count: %d\n",opcount);
	return 0;
}
