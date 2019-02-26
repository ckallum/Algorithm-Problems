#include <stdlib.h>
#include <stdio.h>

void printArray(int array[], int size){
  for (int i = 0; i<size; i++){
    printf("%d, ",array[i]);
  }
  printf("\n");
}

void swap(int array[], int i, int j){
  int temp = array[i];
  array[i] = array[j];
  array[j] = temp;
}
int partition(int array[], int low, int high){
    int target = array[high];
    int i = low -1;

    for (int j = low; j < high; j++){
      if(array[j]<=target){
        i++;
        swap(array, i, j);
      }
    }
    swap(array, i+1, high);
    return (i+1);
}

void quicksort(int a[], int low, int high){
  if (high > low){
      int p = partition(a, low, high);
      quicksort(a, low, p-1);
      quicksort(a, p+1, high);
  }
}

int main(){
  int array[] = {26, 27, 31, 33, 10, 14, 19};
  int arraysize = sizeof(array)/sizeof(array[0]);
  printArray(array, arraysize);
  quicksort(array, 0, arraysize-1);
  printArray(array, arraysize);
  return 0;
}
