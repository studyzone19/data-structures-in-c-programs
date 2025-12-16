/*
Binary search on linked list is inefficient; here we implement binary search
by converting to array first for simplicity.
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct Node{ int data; struct Node *next; } Node;

int main(){
    int n; if(scanf("%d",&n)!=1) return 0;
    Node *head=NULL, *tail=NULL;
    for(int i=0;i<n;i++){ int x; scanf("%d",&x); Node *t=malloc(sizeof(Node)); t->data=x; t->next=NULL; if(!head) head=tail=t; else { tail->next=t; tail=t; } }
    int key; scanf("%d",&key);
    int arr[n], i=0; Node *p=head; while(p){ arr[i++]=p->data; p=p->next; }
    // assume list was sorted
    int l=0,r=n-1,found=-1;
    while(l<=r){
        int m = l+(r-l)/2;
        if(arr[m]==key){ found=m; break; }
        else if(arr[m]<key) l=m+1; else r=m-1;
    }
    if(found==-1) printf("Not found\n"); else printf("Found at index %d\n", found);
    return 0;
}
