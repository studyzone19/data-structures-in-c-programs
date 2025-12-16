/*
Linear search in linked list
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct Node{ int data; struct Node *next; } Node;

int search(Node *head, int key){
    int pos=0;
    while(head){ if(head->data==key) return pos; head=head->next; pos++; }
    return -1;
}

int main(){
    int n; if(scanf("%d",&n)!=1) return 0;
    Node *head=NULL, *tail=NULL;
    for(int i=0;i<n;i++){ int x; scanf("%d",&x); Node *t=malloc(sizeof(Node)); t->data=x; t->next=NULL; if(!head) head=tail=t; else { tail->next=t; tail=t; } }
    int key; scanf("%d",&key);
    int pos = search(head,key);
    if(pos==-1) printf("Not found\n"); else printf("Found at pos %d\n", pos);
    return 0;
}
