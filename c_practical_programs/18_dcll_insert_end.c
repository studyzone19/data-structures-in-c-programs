/*
Doubly Circular Linked List - insert/delete at end
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct Node{ int data; struct Node *prev, *next; } Node;
Node *head = NULL;

void insert_end(int x){
    if(!head){ insert_begin(x); return; }
    Node *tail=head->prev;
    Node *n=malloc(sizeof(Node)); n->data=x;
    n->next=head; n->prev=tail; tail->next=n; head->prev=n;
}

int delete_end(){
    if(!head){ printf("Empty\n"); return -1; }
    if(head->next==head){ int v=head->data; free(head); head=NULL; return v; }
    Node *tail=head->prev; int v=tail->data;
    tail->prev->next = head; head->prev = tail->prev; free(tail); return v;
}

void insert_begin(int x){
    Node *n=malloc(sizeof(Node)); n->data=x;
    if(!head){ n->next=n->prev=n; head=n; return; }
    Node *tail=head->prev; n->next=head; n->prev=tail; tail->next=n; head->prev=n; head=n;
}

int main(){
    int ch,x;
    while(1){
        printf("\n1.ins 2.del 3.show 4.exit\nChoice: ");
        if(scanf("%d",&ch)!=1) break;
        if(ch==1){ printf("Val: "); scanf("%d",&x); insert_end(x); }
        else if(ch==2) printf("Deleted %d\n", delete_end());
        else if(ch==3) { if(!head) printf("NULL\n"); else { Node *p=head; do{ printf("%d <-> ", p->data); p=p->next; } while(p!=head); printf("(back)\n"); } }
        else break;
    }
    return 0;
}
