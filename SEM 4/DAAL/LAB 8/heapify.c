#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
  }
  
 void heapify(int arr[], int n, int i) {
    int greatest = i;
    int leftSide = 2 * i + 1;
    int rightSide = 2 * i + 2;
  
    if (leftSide < n && arr[leftSide] > arr[greatest])
      greatest = leftSide;
  
    if (rightSide < n && arr[rightSide] > arr[greatest])
      greatest = rightSide;
  
    if (greatest != i) {
      swap(&arr[i], &arr[greatest]);
      heapify(arr, n, greatest);
    }
  }
  