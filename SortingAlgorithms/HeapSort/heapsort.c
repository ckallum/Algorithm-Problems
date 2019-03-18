#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
// Functions implementing a priority queue as a binary heap (one of the most
// beautiful data structures in computer science). It is an implicit binary tree
// stored in an array. The children of node i are nodes 2*i+1 and 2*i+2 and the
// parent of node i is node (i-1)/2. (Why so many descriptions start at index 1
// instead of index 0 is a mystery.) The tree is semi-sorted by character count
// so that a node's count is smaller than either of its children. Initial
// semi-sorting is linear, and operations after that are O(log(n)). (Put these
// in a separate module to reuse.)

// Create a queue from a map, including only nodes with non-zero counts.
// Use a forward reference to the buildHeap function below.
void swap(int array[], int s, int last){
  int temp = array[s];
  array[s] = array[last];
  array[last] = temp;
}

void heapify(int array[], int size, int index){
  int l = 2*index+1;
  int r = 2*index+2;
  int max = index;
  if (l<size && array[max] < array[l]){
    max = l;
  }
  if (r<size && array[max]<array[r]){
    max = r;
  }
  if (max!= index){
    swap(array, index, max);
    heapify(array, size, max);
  }

}

/*size-1/2 because the last level of the tree are leaf nodess. There are 2 times more
leaf nodes than parent nodes. Therefore the position of the last parent nodes/
the first parent nodes from right to left of the array will be at size-1/2

The first for loop build's the initial heap, the second for loop sorts the max heap
(swaps first and last element) and calls heapify again at the new root*/
void sort(int array[], int size){
  for (int i = (size-1)/2; i>=0; i--){
    heapify(array, size, i);
  }
  for (int i = size-1; i>=0; i--){
    swap(array, 0, i);
    heapify(array, i, 0);
  }
}

int main(){
  int arr[] = {26, 27, 31, 33, 10, 14, 19};
  int arrsize = sizeof(arr)/sizeof(arr[0]);
  for (int i = 0 ; i<arrsize; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
  sort(arr, arrsize);
  for (int i = 0 ; i<arrsize; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}
