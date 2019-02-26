#include <stdio.h>
#include <stdlib.h>


void merge(int array[], int low, int mid, int high){
  int sizeleft = mid-low+1;
  int sizeright = high - mid;
  int leftarray[sizeleft], rightarray[sizeright];
  int i,j,k;

  for (i = 0 ; i < sizeleft; i++){
    leftarray[i] = array[low+i];
  }
  for (j = 0; j < sizeright; j++){
    rightarray[j] = array[mid+1+j];
  }
  i=0;
  j=0;
  k=low;

  while(i<sizeleft && j<sizeright){
    if (leftarray[i]<=rightarray[j]){
      array[k] = leftarray[i];
      i++;
    }
    else{
      array[k] = rightarray[j];
      j++;
    }
    k++;
  }

  while (i < sizeleft)
    {
        array[k] = leftarray[i];
        i++;
        k++;
    }

  while (j < sizeright)
    {
        array[k] = rightarray[j];
        j++;
        k++;
    }
}

void mergeSort(int array[], int low, int high){
  if (low<high){
    int mid = low+(high-low)/2;
    mergeSort(array, low, mid);
    mergeSort(array, mid+1, high);
    merge(array, low, mid, high);
  }
}

void printArray(int array[], int size){
  for (int i = 0; i<size; i++){
    printf("%d, ",array[i]);
  }
  printf("\n");
}

int main(){
  int array[] = {26, 27, 31, 33, 10, 14, 19};
  int arraysize = sizeof(array)/sizeof(array[0]);
  printArray(array, arraysize);
  mergeSort(array, 0, arraysize-1);
  printArray(array, arraysize);
  return 0;
}
