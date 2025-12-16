/*
Queue using linked list
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *next; } Node;
Node *front = NULL, *rear = NULL;

void enqueue(int x){
    Node *n = malloc(sizeof(Node));
    n->data = x; n->next = NULL;
    if(!rear) front = rear = n;
    else { rear->next = n; rear = n; }
}

int dequeue(){
    if(!front){ printf("Empty\n"); return -1; }
    Node *t = front; int v = t->data;
    front = front->next;
    if(!front) rear = NULL;
    free(t);
    return v;
}

int main(){
    int ch,x;
    while(1){
        printf("\n1.enq 2.deq 3.exit\nChoice: ");
        if(scanf("%d",&ch)!=1) break;
        if(ch==1){ printf("Val: "); scanf("%d",&x); enqueue(x); }
        else if(ch==2) printf("Dequeued %d\n", dequeue());
        else break;
    }
    return 0;
}
