/*
Singly Circular Linked List - insert/delete at beginning
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct Node{ int data; struct Node *next; } Node;
Node *head = NULL;

void insert_begin(int x){
    Node *n=malloc(sizeof(Node)); n->data=x;
    if(!head){ n->next=n; head=n; return; }
    Node *p=head;
    while(p->next!=head) p=p->next;
    n->next=head; p->next=n; head=n;
}

int delete_begin(){
    if(!head){ printf("Empty\n"); return -1; }
    if(head->next==head){ int v=head->data; free(head); head=NULL; return v; }
    Node *p=head;
    while(p->next!=head) p=p->next;
    Node *t=head; int v=t->data; head=head->next; p->next=head; free(t); return v;
}

void display(){ if(!head){ printf("NULL\n"); return; } Node *p=head;
    do{ printf("%d -> ", p->data); p=p->next; } while(p!=head);
    printf("(back to head)\n");
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
