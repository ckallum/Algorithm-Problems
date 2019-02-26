#include <stdlib.h>
#include <stdio.h>

void printArray(int array[], int size){
  for (int i = 0; i<size; i++){
    printf("%d, ",array[i]);
  }
  printf("\n");
}

void BubbleSort(int array[], int size){
  for (int i = 0; i<size-1; i++){
    for (int j = i+1; j<size ; j++){
      if(array[i]>array[j]){
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }
    }
  }
}

int main(){
  int array[] = {41,26, 27, 31, 33, 10, 14, 19};
  int arraysize = sizeof(array)/sizeof(array[0]);
  printArray(array, arraysize);
  BubbleSort(array, arraysize);
  printArray(array, arraysize);
  return 0;
}
