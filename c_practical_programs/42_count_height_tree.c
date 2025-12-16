/*
Count nodes and compute height of binary tree
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct Node{ int data; struct Node *left,*right; } Node;
Node* newNode(int x){ Node* n=malloc(sizeof(Node)); n->data=x; n->left=n->right=NULL; return n; }
int countNodes(Node* r){ if(!r) return 0; return 1 + countNodes(r->left) + countNodes(r->right); }
int height(Node* r){ if(!r) return 0; int lh=height(r->left), rh=height(r->right); return 1 + (lh>rh?lh:rh); }
int main(){ Node *root=newNode(1); root->left=newNode(2); root->right=newNode(3); root->left->left=newNode(4);
printf("Count=%d Height=%d\n", countNodes(root), height(root)); return 0; }
