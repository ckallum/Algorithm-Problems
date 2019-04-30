#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>


void SearchMatrix(int A[4][4], int value){
  int j=3, i=0;
  while(i<4 && j>=0){
    if(A[i][j] == value){
      printf("%d found at index: %d, %d\n", value, i,j);
      return;
    }
    else if(A[i][j]<value){
      i++;
    }
    else j--;
  }
}

int main(){
  int A[4][4] = { {10, 20, 30, 40},
                    {15, 25, 35, 45},
                    {27, 29, 37, 48},
                    {32, 33, 39, 50},
                };
  SearchMatrix(A, 29);
}
