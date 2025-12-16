/*
Linear search in array
*/
#include <stdio.h>

int linear_search(int arr[], int n, int key){
    for(int i=0;i<n;i++) if(arr[i]==key) return i;
    return -1;
}

int main(){
    int n; printf("n: "); if(scanf("%d",&n)!=1) return 0;
    int arr[n]; for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    int key; printf("key: "); scanf("%d",&key);
    int idx = linear_search(arr,n,key);
    if(idx==-1) printf("Not found\n"); else printf("Found at index %d\n", idx);
    return 0;
}
