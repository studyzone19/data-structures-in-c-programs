/*
Postorder traversal (recursive)
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct Node{ int data; struct Node *left,*right; } Node;
Node* newNode(int x){ Node* n=malloc(sizeof(Node)); n->data=x; n->left=n->right=NULL; return n; }
void postorder(Node* r){ if(!r) return; postorder(r->left); postorder(r->right); printf("%d ", r->data); }
int main(){ Node *root=newNode(1); root->left=newNode(2); root->right=newNode(3); root->left->left=newNode(4); postorder(root); printf("\n"); return 0; }
