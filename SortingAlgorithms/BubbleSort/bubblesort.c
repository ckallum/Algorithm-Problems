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

void bubbleback(int array[], int size){
  for (int i = 0; i<size ; i++){
    for (int j =0 ; j< size-i-1; j++){
      if (array[j] > array[j+1]){
        int temp = array[j+1];
        array[j]= array[j+1];
        array[j] = temp;
      }
    }
  }
}

int main(){
  printf("Front to Back:\n");
  int array[] = {41,26, 27, 31, 33, 10, 14, 19};
  int arraysize = sizeof(array)/sizeof(array[0]);
  printArray(array, arraysize);
  BubbleSort(array, arraysize);
  printArray(array, arraysize);
  printf("\n" );
  printf("Back to Front:\n");
  int array2[] = {41,26, 27, 31, 33, 10, 14, 19};
  int arraysize2 = sizeof(array2)/sizeof(array2[0]);
  printArray(array2, arraysize2);
  BubbleSort(array2, arraysize2);
  printArray(array2, arraysize2);
  return 0;
}
