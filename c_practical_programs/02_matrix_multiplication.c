/*
Matrix Multiplication (standard algorithm)
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int r1,c1,r2,c2;
    printf("Enter rows and cols of A: ");
    if (scanf("%d %d",&r1,&c1)!=2) return 0;
    printf("Enter rows and cols of B: ");
    if (scanf("%d %d",&r2,&c2)!=2) return 0;
    if (c1!=r2) { printf("Incompatible for multiplication\n"); return 0; }

    int A[r1][c1], B[r2][c2], C[r1][c2];
    printf("Enter A:\n");
    for(int i=0;i<r1;i++) for(int j=0;j<c1;j++) scanf("%d",&A[i][j]);
    printf("Enter B:\n");
    for(int i=0;i<r2;i++) for(int j=0;j<c2;j++) scanf("%d",&B[i][j]);

    for(int i=0;i<r1;i++) for(int j=0;j<c2;j++) {
        C[i][j]=0;
        for(int k=0;k<c1;k++) C[i][j]+=A[i][k]*B[k][j];
    }

    printf("Result:\n");
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++) printf("%d ", C[i][j]);
        printf("\n");
    }
    return 0;
}
