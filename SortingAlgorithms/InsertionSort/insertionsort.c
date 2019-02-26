#include <stdlib.h>
#include <stdio.h>

void printArray(int array[], int size){
  for (int i = 0; i<size; i++){
    printf("%d, ",array[i]);
  }
  printf("\n");
}

void InsertionSort(int a[], int size){
  for (int i =1; i<size; i++){
    int j = i-1;
    int insertion = a[i];
    while(j>=0 && insertion<a[j]){
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = insertion;
  }
}

int main(){
  int array[] = {26, 27, 31, 33, 10, 14, 19};
  int arraysize = sizeof(array)/sizeof(array[0]);
  printArray(array, arraysize);
  InsertionSort(array, arraysize);
  printArray(array, arraysize);
  return 0;
}
