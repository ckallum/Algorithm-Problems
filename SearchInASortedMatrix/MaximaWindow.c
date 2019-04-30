#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

void MaximaWindow(int A[], int size){
  int B[size/2];
  for(int i =0; i<size/2 ; i++){
    B[i] = 0;
  }
  for (int i = (size/2)-1; i>=0; i--){
    if(A[i]>B[i]){
      B[i] = A[i];
    }
    if(i<(size/2)-2){
      if(B[i+1]>B[i]){
        B[i] = B[i+1];
      }
    }

  }
  for(int i = (size/2); i<size; i++){
    if(A[i] > B[i-(size/2)]){
      B[i-(size/2)] = A[i];
    }
    if(i<size-1){
      if(B[i-(size/2)]>B[(i-(size/2))+1]){
        B[(i-(size/2))+1] = B[i-(size/2)];
      }
    }

  }
  for(int i = 0; i<size/2;i++){
    printf("%d\n", B[i]);
  }
}

int main(){
  int A[] = {10,23,43,9,3,4,6,10,35,60,78,60};
  int arraysize = sizeof(A)/sizeof(A[0]);
  MaximaWindow(A, arraysize);


}
