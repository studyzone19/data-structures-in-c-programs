/*
Create Binary Tree (level-order insertion) and simple traversals
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{ int data; struct Node *left, *right; } Node;

Node* newNode(int x){ Node* n=malloc(sizeof(Node)); n->data=x; n->left=n->right=NULL; return n; }

int main(){
    // For simplicity: build tree from array level-order with -1 as NULL
    int n; if(scanf("%d",&n)!=1) return 0;
    int a[n]; for(int i=0;i<n;i++) scanf("%d",&a[i]);
    Node* nodes[n];
    for(int i=0;i<n;i++) nodes[i] = (a[i]==-1)? NULL : newNode(a[i]);
    for(int i=0;i<n;i++){
        if(nodes[i]){
            int l = 2*i+1, r = 2*i+2;
            if(l<n) nodes[i]->left = nodes[l];
            if(r<n) nodes[i]->right = nodes[r];
        }
    }
    // print inorder
    void inorder(Node* r){ if(!r) return; inorder(r->left); printf("%d ", r->data); inorder(r->right); }
    inorder(nodes[0]); printf("\n");
    return 0;
}
