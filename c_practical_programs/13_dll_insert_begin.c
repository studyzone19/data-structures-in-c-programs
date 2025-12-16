/*
Doubly Linked List - insert/delete at beginning
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct Node{ int data; struct Node *prev, *next; } Node;
Node *head = NULL;

void insert_begin(int x){
    Node *n=malloc(sizeof(Node)); n->data=x; n->prev=NULL; n->next=head;
    if(head) head->prev=n;
    head=n;
}

int delete_begin(){
    if(!head){ printf("Empty\n"); return -1; }
    Node *t=head; int v=t->data; head=head->next;
    if(head) head->prev=NULL; free(t); return v;
}

void display(){
    Node *p=head; while(p){ printf("%d <-> ", p->data); p=p->next; } printf("NULL\n");
}

int main(){
    int ch,x;
    while(1){
        printf("\n1.ins 2.del 3.show 4.exit\nChoice: ");
        if(scanf("%d",&ch)!=1) break;
        if(ch==1){ printf("Val: "); scanf("%d",&x); insert_begin(x); }
        else if(ch==2) printf("Deleted %d\n", delete_begin());
        else if(ch==3) display();
        else break;
    }
    return 0;
}
