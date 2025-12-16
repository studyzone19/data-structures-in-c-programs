/*
Sorting on linked list (using merge sort for linked lists)
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct Node{ int data; struct Node *next; } Node;

Node* merge(Node* a, Node* b){
    if(!a) return b; if(!b) return a;
    Node *res=NULL;
    if(a->data <= b->data){ res=a; res->next = merge(a->next,b); }
    else { res=b; res->next = merge(a,b->next); }
    return res;
}

void front_back_split(Node* src, Node** front, Node** back){
    Node *fast, *slow; slow=src; fast=src->next;
    while(fast){ fast=fast->next; if(fast){ slow=slow->next; fast=fast->next; } }
    *front = src; *back = slow->next; slow->next = NULL;
}

void mergeSort(Node** headRef){
    Node *head = *headRef;
    if(!head || !head->next) return;
    Node *a,*b;
    front_back_split(head,&a,&b);
    mergeSort(&a); mergeSort(&b);
    *headRef = merge(a,b);
}

int main(){
    int n; if(scanf("%d",&n)!=1) return 0;
    Node *head=NULL, *tail=NULL;
    for(int i=0;i<n;i++){ int x; scanf("%d",&x); Node *t=malloc(sizeof(Node)); t->data=x; t->next=NULL; if(!head) head=tail=t; else { tail->next=t; tail=t; } }
    mergeSort(&head);
    for(Node *p=head;p;p=p->next) printf("%d ", p->data);
    printf("\n"); return 0;
}
