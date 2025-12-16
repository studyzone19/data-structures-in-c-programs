/*
Binary Search Tree: insert and search
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct Node{ int data; struct Node *left,*right; } Node;
Node* newNode(int x){ Node* n=malloc(sizeof(Node)); n->data=x; n->left=n->right=NULL; return n; }
Node* insert(Node* root,int x){ if(!root) return newNode(x); if(x<root->data) root->left=insert(root->left,x); else root->right=insert(root->right,x); return root; }
int search(Node* root,int x){ if(!root) return 0; if(root->data==x) return 1; if(x<root->data) return search(root->left,x); return search(root->right,x); }
void inorder(Node* r){ if(!r) return; inorder(r->left); printf("%d ", r->data); inorder(r->right); }
int main(){ Node *root=NULL; int n; if(scanf("%d",&n)!=1) return 0; for(int i=0;i<n;i++){ int x; scanf("%d",&x); root=insert(root,x); } inorder(root); printf("\n"); int key; scanf("%d",&key); printf("%s\n", search(root,key)? "Found":"Not Found"); return 0; }
