/*
Check if tree is BST using range constraints
*/
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
typedef struct Node{ int data; struct Node *left,*right; } Node;
Node* newNode(int x){ Node* n=malloc(sizeof(Node)); n->data=x; n->left=n->right=NULL; return n; }

int isBSTUtil(Node* node, int min, int max){
    if(!node) return 1;
    if(node->data < min || node->data > max) return 0;
    return isBSTUtil(node->left, min, node->data-1) && isBSTUtil(node->right, node->data+1, max);
}

int main(){
    Node *root=newNode(3); root->left=newNode(2); root->right=newNode(5);
    printf("%s\n", isBSTUtil(root, INT_MIN, INT_MAX) ? "BST" : "Not BST");
    return 0;
}
