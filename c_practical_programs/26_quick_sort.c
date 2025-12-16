/*
Quick sort (recursive)
*/
#include <stdio.h>

void swap(int *a,int *b){ int t=*a; *a=*b; *b=t; }

int partition(int a[], int l,int h){
    int pivot=a[h], i=l-1;
    for(int j=l;j<=h-1;j++){
        if(a[j]<=pivot){ i++; swap(&a[i],&a[j]); }
    }
    swap(&a[i+1], &a[h]);
    return i+1;
}

void quick(int a[], int l,int h){
    if(l<h){
        int p = partition(a,l,h);
        quick(a,l,p-1); quick(a,p+1,h);
    }
}

int main(){ int n; scanf("%d",&n); int a[n]; for(int i=0;i<n;i++) scanf("%d",&a[i]); quick(a,0,n-1); for(int i=0;i<n;i++) printf("%d ",a[i]); printf("\n"); return 0; }
