/*
Stack implementation using array
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int stack[MAX], top = -1;

void push(int x){
    if(top==MAX-1){ printf("Overflow\n"); return; }
    stack[++top]=x;
}

int pop(){
    if(top==-1){ printf("Underflow\n"); return -1; }
    return stack[top--];
}

int peek(){
    if(top==-1) return -1;
    return stack[top];
}

int main(){
    int choice, x;
    while(1){
        printf("\n1.push 2.pop 3.peek 4.exit\nChoice: ");
        if (scanf("%d",&choice)!=1) break;
        if(choice==1){ printf("Value: "); scanf("%d",&x); push(x); }
        else if(choice==2) printf("Popped: %d\n", pop());
        else if(choice==3) printf("Top: %d\n", peek());
        else break;
    }
    return 0;
}
