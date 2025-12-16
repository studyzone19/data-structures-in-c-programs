/*
Preorder traversal (recursive)
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{ int data; struct Node *left,*right; } Node;
Node* newNode(int x){ Node* n=malloc(sizeof(Node)); n->data=x; n->left=n->right=NULL; return n; }

void preorder(Node* r){ if(!r) return; printf("%d ", r->data); preorder(r->left); preorder(r->right); }

int main(){
    // quick demo: build small tree
    Node *root = newNode(1);
    root->left=newNode(2); root->right=newNode(3);
    root->left->left=newNode(4);
    preorder(root); printf("\n");
    return 0;
}
