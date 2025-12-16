/*
Level order traversal using queue
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{ int data; struct Node *left,*right; } Node;
Node* newNode(int x){ Node* n=malloc(sizeof(Node)); n->data=x; n->left=n->right=NULL; return n; }

typedef struct QNode{ Node* node; struct QNode *next; } QNode;
void enqueue(QNode **rear, QNode **front, Node* node){
    QNode *n=malloc(sizeof(QNode)); n->node=node; n->next=NULL;
    if(!*front) *front=*rear=n; else { (*rear)->next=n; *rear=n; }
}
Node* dequeue(QNode **front, QNode **rear){
    if(!*front) return NULL;
    QNode *t=*front; Node* n=t->node; *front=(*front)->next; if(!*front) *rear=NULL; free(t); return n;
}

void levelOrder(Node* root){
    QNode *front=NULL,*rear=NULL;
    enqueue(&rear,&front,root);
    while((root=dequeue(&front,&rear))){
        printf("%d ", root->data);
        if(root->left) enqueue(&rear,&front,root->left);
        if(root->right) enqueue(&rear,&front,root->right);
    }
}

int main(){
    Node *root=newNode(1); root->left=newNode(2); root->right=newNode(3);
    root->left->left=newNode(4); root->left->right=newNode(5);
    levelOrder(root); printf("\n");
    return 0;
}
