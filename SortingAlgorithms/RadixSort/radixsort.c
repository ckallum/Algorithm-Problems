#include <stdio.h>
#include <stdlib.h>

void printArray(int array[], int size){
  for (int i = 0; i<size; i++){
    printf("%d, ",array[i]);
  }
  printf("\n");
}

int *countingSort(int array[], int k, int size){
  int C[k+1];
  for(int i=0; i<=k;i++){
    C[i] = 0;
  }
  int *B=malloc(size*sizeof(int));
  for(int i=0; i<size; i++){
    C[array[i]]++;
  }

  for(int i = 1;i<=k; i++){
    C[i] = C[i]+C[i-1];
  }

  for(int i = size-1; i>=0 ;i--){
    B[C[array[i]]-1] = array[i];
    C[array[i]]--;
  }
  return B;
}

int findMax(int array[], int size){
  int max = 0;
  for(int i = 0; i <size; i++){
    if(array[i]>max){
      max = array[i];
    }
  }
  return max;
}

int main(){
  int array[] = {26, 27, 31, 33, 10, 14, 19};
  int arraysize = sizeof(array)/sizeof(array[0]);
  printArray(array, arraysize);
  int k = findMax(array, arraysize);
  int *sorted = countingSort(array, k, arraysize);
  printArray(sorted, arraysize);
  return 0;
}
