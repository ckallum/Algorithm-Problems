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
  (*new) = (node){NULL,NULL, val};
  return new;
}

void freeTree(node *root){
  if(root == NULL)return;
  freeTree(root->left);
  freeTree(root->right);
  free(root);
}

void insertNode(node *n, int val){
  if(n->left == NULL){
    n->left = newNode(val);
  }
  else if(n->right == NULL){
    n->right = newNode(val);
  }
  else{
    if(val<n->left->val){
      insertNode(n->left, val);
    }
    else insertNode(n->right,val);
  }
}

int main(){
  node *root = newNode(10);
  insertNode(root, 20);
  insertNode(root, 30);
  insertNode(root, 40);
  insertNode(root, 50);
  insertNode(root, 60);
  assert(root->left->val == 20);
  // freeTree(root);
  printf("hello\n");
  return 0;
}
