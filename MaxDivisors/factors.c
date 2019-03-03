#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(){
  int *array = (int*)malloc(sizeof(int));
  int arrayindex = 0;
  int max = 0;
  for (int i = 1; i<100; i++){
    int counter = 0;
    for (int j =1; j<100; j++){
      if(i%j==0){
        counter++;
      }
    }
    if (counter>max){
      max = counter;
      array = (int*)realloc(array, sizeof(int));
      arrayindex = 0;
      array[arrayindex] = i;
      arrayindex ++;
    }
    else if (counter==max){
      array = (int*)realloc(array, sizeof(int)*(arrayindex+1));
      array[arrayindex] = i;
      arrayindex++;
    }
  }
  for (int i =0; i<arrayindex; i++){
    printf("%d\n", array[i]);
  }

  for(int i = 0; i < arrayindex; i++){
    printf("%d\n", array[i]);
  }
  free(array);
  return 0;
}
