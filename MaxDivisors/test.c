#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(){
  int *array = (int *)malloc(2*sizeof(int));
  array[0] = 0;
  array[1] = 1;
  printf("%d %d\n", array[0], array[1]);
  array = (int *)realloc(array, sizeof(int)*4);
  array[2] = 2;
  printf("%d %d\n", array[1], array[2]);
  free(array);
  return 0;
}
