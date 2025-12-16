/*
Stack using linked list
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* top = NULL;

void push(int x){
    Node* n = malloc(sizeof(Node));
    n->data = x;
    n->next = top;
    top = n;
}

int pop(){
    if (!top){ printf("Underflow\n"); return -1; }
    Node* t = top;
    int v = t->data;
    top = top->next;
    free(t);
    return v;
}

int peek(){
    return top ? top->data : -1;
}

int main(){
    int ch,x;
    while(1){
        printf("\n1.push 2.pop 3.peek 4.exit\nChoice: ");
        if(scanf("%d",&ch)!=1) break;
        if(ch==1){ printf("Val: "); scanf("%d",&x); push(x); }
        else if(ch==2) printf("Popped %d\n", pop());
        else if(ch==3) printf("Top %d\n", peek());
        else break;
    }
    return 0;
}
