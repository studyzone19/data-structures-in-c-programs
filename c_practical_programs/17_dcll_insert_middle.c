/*
Doubly Circular Linked List - insert/delete at middle (by position)
*/
#include <stdio.h>

#include <stdlib.h>
typedef struct Node{ int data; struct Node *prev, *next; } Node;
Node *head = NULL;

void insert_pos(int x,int pos){
    if(!head || pos<=1){ insert_begin(x); return; }
    Node *p=head; for(int i=1;i<pos-1;i++) p=p->next;
    Node *n=malloc(sizeof(Node)); n->data=x;
    n->next = p->next; n->prev = p;
    p->next->prev = n; p->next = n;
}

int delete_pos(int pos){
    if(!head){ printf("Empty\n"); return -1; }
    if(pos<=1) return delete_begin();
    Node *p=head; for(int i=1;i<pos;i++) p=p->next;
    int v=p->data;
    p->prev->next = p->next; p->next->prev = p->prev;
    free(p); return v;
}

void insert_begin(int x){
    Node *n=malloc(sizeof(Node)); n->data=x;
    if(!head){ n->next=n->prev=n; head=n; return; }
    Node *tail=head->prev; n->next=head; n->prev=tail; tail->next=n; head->prev=n; head=n;
}

int delete_begin(){
    if(!head) return -1;
    if(head->next==head){ int v=head->data; free(head); head=NULL; return v; }
    Node *tail=head->prev; Node *t=head; int v=t->data; head=head->next; tail->next=head; head->prev=tail; free(t); return v;
}

void display(){ if(!head){ printf("NULL\n"); return; } Node *p=head; do{ printf("%d <-> ", p->data); p=p->next; } while(p!=head); printf("(back)\n"); }

int main(){
    int ch,x,pos;
    while(1){
        printf("\n1.ins 2.del 3.show 4.exit\nChoice: ");
        if(scanf("%d",&ch)!=1) break;
        if(ch==1){ printf("Val pos: "); scanf("%d %d",&x,&pos); insert_pos(x,pos); }
        else if(ch==2){ printf("Pos: "); scanf("%d",&pos); printf("Deleted %d\n", delete_pos(pos)); }
        else if(ch==3) display();
        else break;
    }
    return 0;
}
