/*
Sparse Matrix Representation using 3-tuple (row, col, value)
Simple program: read matrix, store non-zero elements and display.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int r, c, val;
} Triple;

int main() {
    int R, C;
    printf("Enter rows and cols: ");
    if (scanf("%d %d", &R, &C)!=2) return 0;
    int mat[R][C];
    printf("Enter matrix (%d x %d):\n", R, C);
    for (int i=0;i<R;i++) for (int j=0;j<C;j++) scanf("%d",&mat[i][j]);

    // count non-zero
    int count=0;
    for (int i=0;i<R;i++) for (int j=0;j<C;j++) if (mat[i][j]!=0) count++;

    Triple *triples = malloc(sizeof(Triple)*count);
    int idx=0;
    for (int i=0;i<R;i++) for (int j=0;j<C;j++) if (mat[i][j]!=0) {
        triples[idx].r = i;
        triples[idx].c = j;
        triples[idx].val = mat[i][j];
        idx++;
    }

    printf("\n3-tuple representation (row col value):\n");
    for (int i=0;i<count;i++) {
        printf("%d %d %d\n", triples[i].r, triples[i].c, triples[i].val);
    }

    free(triples);
    return 0;
}
