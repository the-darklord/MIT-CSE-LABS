#include "heapify.c"

void topdown(int* arr,int n){
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
		if(i >= 2)
		heapify(arr,i+1,i/2-1);
	}

}

int main(){
	int n = 5;
	int* arr = (int*)calloc(n,sizeof(int));
  
	topdown(arr,n);

    printf("Max Heap is \n");
   	for(int i=0;i<n;i++){
   		printf("%d ",arr[i]);
   	}
}