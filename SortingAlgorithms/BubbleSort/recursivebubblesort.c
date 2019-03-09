#include <stdlib.h>
#include <stdio.h>

void swap (int array[], int i, int j){
  int temp = array[i];
  array[i] = array[j];
  array[j] = temp;
}

void bubble(int array[], int size){
  if (size == 0) return;

  for (int i = 0 ; i<size-1; i++){
    if (array[i] > array[i+1]){
      swap(array, i, i+1);
    }
  }
  bubble(array, size-1);
}
void printArray(int array[], int size){
  for (int i = 0; i<size; i++){
    printf("%d, ",array[i]);
  }
  printf("\n");
}

int main(){
  int array[] = {41,26, 27, 31, 33, 10, 14, 19};
  int arraysize = sizeof(array)/sizeof(array[0]);
  printArray(array, arraysize);
  bubble(array, arraysize);
  printArray(array, arraysize);
  return 0;
}
