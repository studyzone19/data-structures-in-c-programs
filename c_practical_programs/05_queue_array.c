/*
Queue using array (circular)
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int q[MAX], front = -1, rear = -1;

int isEmpty(){ return front==-1; }
int isFull(){ return (rear+1)%MAX == front; }

void enqueue(int x){
    if(isFull()){ printf("Full\n"); return; }
    if(isEmpty()){ front=rear=0; q[rear]=x; return; }
    rear = (rear+1)%MAX; q[rear]=x;
}

int dequeue(){
    if(isEmpty()){ printf("Empty\n"); return -1; }
    int v = q[front];
    if(front==rear) front=rear=-1;
    else front = (front+1)%MAX;
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
