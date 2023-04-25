#include "heapify.c"

 void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);
  
    for (int i = n - 1; i >= 0; i--) {
      swap(&arr[0], &arr[i]);
  
      heapify(arr, i, 0);
    }
  }

int main(){
	int arr[] = {5,1,3,2,6,4};
  int n = 6;

  heapSort(arr, n);

  printf("Sorted array is \n");
 	for(int i=0;i<n;i++){
 		printf("%d ",arr[i]);
 	}
 }