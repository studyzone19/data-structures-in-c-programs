/*
Postfix to Infix conversion (operands single-char)
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* concat(char *a, char *b, char *op){
    int la=strlen(a), lb=strlen(b);
    char *res = malloc(la+lb+4);
    sprintf(res, "(%s%s%s)", a, op, b);
    return res;
}

int main(){
    char s[200]; scanf("%s", s);
    char *stack[200]; int top=-1;
    for(int i=0;s[i];i++){
        char c=s[i];
        if(isalnum(c)){
            char *t=malloc(2); t[0]=c; t[1]=0; stack[++top]=t;
        } else {
            char *b=stack[top--]; char *a=stack[top--];
            char op[2]; op[0]=c; op[1]=0;
            char *r = concat(a,b,op);
            stack[++top]=r;
        }
    }
    printf("%s\n", stack[top]);
    return 0;
}
