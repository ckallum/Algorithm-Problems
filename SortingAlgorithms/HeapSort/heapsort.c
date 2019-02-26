#include <stdlib.h>
#include <stdio.h>
// Functions implementing a priority queue as a binary heap (one of the most
// beautiful data structures in computer science). It is an implicit binary tree
// stored in an array. The children of node i are nodes 2*i+1 and 2*i+2 and the
// parent of node i is node (i-1)/2. (Why so many descriptions start at index 1
// instead of index 0 is a mystery.) The tree is semi-sorted by character count
// so that a node's count is smaller than either of its children. Initial
// semi-sorting is linear, and operations after that are O(log(n)). (Put these
// in a separate module to reuse.)

struct queue { int length; int array[]; };
typedef struct queue queue;

// Create a queue from a map, including only nodes with non-zero counts.
// Use a forward reference to the buildHeap function below.
void sort(queue *q);
queue *newQueue(int array[], int size) {
    queue *q = malloc(sizeof(queue));
    q->length = 0;
    for (int i = 0; i < size; i++) {
          q->array[q->length] = array[i];
          q->length++;
    }
    sort(q);
    return q;
}

// Free a queue, but not the nodes in it.
void freeQueue(queue *q) {
    free(q);
}

// Swap two nodes of an array. (Make static and inline for efficiency.)
void swap(node *nodes[], int i, int j) {
    node *temp = nodes[i];
    nodes[i] = nodes[j];
    nodes[j] = temp;
}

// Move node i up to the right place, iteratively. This function is often called
// heapifyUp or siftUp or bubbleUp...
void up(queue *q, int i) {
    bool done = false;
    while (i > 0 && ! done) {
        int parent = (i - 1)/2;
        if (q->array[parent]->n < q->array[i]->n) done = true;
        else swap(q->array, i, parent);
        i = parent;
    }
}

// Move node i down to the right place, iteratively. This function is often
// called heapifyDown, siftDown, bubbleDown, ...
void down(queue *q, int i) {
    bool done = false;
    while (! done) {
        int left = 2*i + 1, right = 2*i + 2;
        int smallest = i;
        if (left < q->length && q->array[left]->n < q->array[i]->n) {
            smallest = left;
        }
        if (right < q->length && q->array[right]->n < q->array[smallest]->n) {
            smallest = right;
        }
        if (smallest == i) done = true;
        else swap(q->array, i, smallest);
        i = smallest;
    }
}

// Extract the lowest priority item from a binary heap.
node *extract(queue *q) {
    node *smallest = q->array[0];
    q->length--;
    q->array[0] = q->array[q->length];
    down(q, 0);
    return smallest;
}

// Insert a node into a binary heap.
void insert(queue *q, node *p) {
    int n = q->length;
    q->array[n] = p;
    q->length++;
    up(q, n);
}

// Semi-sort all of the original nodes.
void sort(queue *q) {
    for (int i = q->length/2; i >= 0; i--) down(q, i);
}
int main(){
  return;
}
