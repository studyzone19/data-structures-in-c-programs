/*
Singly Circular Linked List - insert/delete at middle (by position)
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct Node{ int data; struct Node *next; } Node;
Node *head = NULL;

void insert_pos(int x,int pos){
    if(pos<=1){ // same as insert begin
        Node *n=malloc(sizeof(Node)); n->data=x;
        if(!head){ n->next=n; head=n; return; }
        Node *p=head; while(p->next!=head) p=p->next;
        n->next=head; p->next=n; head=n; return;
    }
    Node *p=head;
    for(int i=1;i<pos-1 && p->next!=head;i++) p=p->next;
    Node *n=malloc(sizeof(Node)); n->data=x; n->next=p->next; p->next=n;
}

int delete_pos(int pos){
    if(!head){ printf("Empty\n"); return -1; }
    if(pos<=1) {
        if(head->next==head){ int v=head->data; free(head); head=NULL; return v; }
        Node *p=head; while(p->next!=head) p=p->next;
        Node *t=head; int v=t->data; head=head->next; p->next=head; free(t); return v;
    }
    Node *p=head;
    for(int i=1;i<pos-1 && p->next!=head;i++) p=p->next;
    if(p->next==head){ printf("Invalid\n"); return -1; }
    Node *t=p->next; int v=t->data; p->next=t->next; free(t); return v;
}

void display(){ if(!head){ printf("NULL\n"); return; } Node *p=head;
    do{ printf("%d -> ", p->data); p=p->next; } while(p!=head);
    printf("(back to head)\n");
}

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
