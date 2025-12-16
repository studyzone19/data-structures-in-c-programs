/*
Mirror image of binary tree (swap left and right recursively)
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct Node{ int data; struct Node *left,*right; } Node;
Node* newNode(int x){ Node* n=malloc(sizeof(Node)); n->data=x; n->left=n->right=NULL; return n; }
void mirror(Node* r){ if(!r) return; Node* t=r->left; r->left=r->right; r->right=t; mirror(r->left); mirror(r->right); }
void inorder(Node* r){ if(!r) return; inorder(r->left); printf("%d ", r->data); inorder(r->right); }
int main(){ Node *root=newNode(1); root->left=newNode(2); root->right=newNode(3); root->left->left=newNode(4);
printf("Before: "); inorder(root); printf("\n"); mirror(root); printf("After: "); inorder(root); printf("\n"); return 0; }
