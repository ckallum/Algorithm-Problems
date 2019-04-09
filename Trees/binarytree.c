#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node{
  struct node *left;
  struct node *right;
  int val;
};
typedef struct node node;

node *newNode(int val){
  node *new = malloc(sizeof(node));
  (*new) =(node){NULL,NULL,val};
  return new;
}

void freeTree(node *root){
  if(root == NULL)return;
  freeTree(root->left);
  freeTree(root->right);
  free(root);
}

struct node* insertNode(node *n, int val){
  if (n == NULL) return newNode(val);
  if(val<n->val){
    n->left = insertNode(n->left, val);
  }
  else if(val>n->val){
    n->right = insertNode(n->right,val);
  }
  return n;
}

void printinorder(struct node *root)
{
    if (root != NULL)
    {
        printinorder(root->left);
        printf("%d \n", root->val);
        printinorder(root->right);
    }
}

int main(){
  node *root = NULL;
  root = insertNode(root, 35);
  insertNode(root, 20);
  insertNode(root, 45);
  insertNode(root, 15);
  insertNode(root, 25);
  insertNode(root, 40);
  insertNode(root, 50);
  printinorder(root);
  freeTree(root);
  return 0;
}
/*
             35
           /    \
         20     45
        / \    /  \
      15  25  40  50
                    */
/*The leftmost  branch will always contain the smallest values. All values
down the left branch of a node will always be smaller than the node which
is why we do leftmost traversal first when printing and then look at the right
branches node by node when working back up the tree.  */
