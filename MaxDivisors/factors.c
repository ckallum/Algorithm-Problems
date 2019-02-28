#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(){
  int array[100];
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
      arrayindex = 0;
      array[arrayindex] = i;
      arrayindex ++;
    }
    else if (counter==max){
      array[arrayindex] = i;
      arrayindex++;
    }
  }
  for (int i =0; i<arrayindex; i++){
    printf("%d\n", array[i]);
  }
  return 0;

}
