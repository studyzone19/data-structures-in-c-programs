/*
Inorder traversal (recursive)
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct Node{ int data; struct Node *left,*right; } Node;
Node* newNode(int x){ Node* n=malloc(sizeof(Node)); n->data=x; n->left=n->right=NULL; return n; }
void inorder(Node* r){ if(!r) return; inorder(r->left); printf("%d ", r->data); inorder(r->right); }
int main(){ Node *root=newNode(1); root->left=newNode(2); root->right=newNode(3); root->left->left=newNode(4); inorder(root); printf("\n"); return 0; }
