/*
Doubly Linked List - insert/delete at end
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct Node{ int data; struct Node *prev, *next; } Node;
Node *head = NULL;

void insert_end(int x){
    Node *n=malloc(sizeof(Node)); n->data=x; n->next=NULL;
    if(!head){ n->prev=NULL; head=n; return; }
    Node *p=head; while(p->next) p=p->next;
    p->next=n; n->prev=p;
}

int delete_end(){
    if(!head){ printf("Empty\n"); return -1; }
    Node *p=head;
    if(!p->next){ int v=p->data; free(p); head=NULL; return v; }
    while(p->next) p=p->next;
    int v=p->data; p->prev->next=NULL; free(p); return v;
}

void display(){ Node *p=head; while(p){ printf("%d <-> ", p->data); p=p->next; } printf("NULL\n"); }

int main(){
    int ch,x;
    while(1){
        printf("\n1.ins 2.del 3.show 4.exit\nChoice: ");
        if(scanf("%d",&ch)!=1) break;
        if(ch==1){ printf("Val: "); scanf("%d",&x); insert_end(x); }
        else if(ch==2) printf("Deleted %d\n", delete_end());
        else if(ch==3) display();
        else break;
    }
    return 0;
}
