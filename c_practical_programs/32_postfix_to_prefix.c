/*
Postfix to Prefix conversion
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* concat(char *a, char *b, char op){
    int la=strlen(a), lb=strlen(b);
    char *res = malloc(la+lb+3);
    res[0]=op; res[1]=0;
    strcat(res, a); strcat(res, b);
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
            char *r = malloc(strlen(a)+strlen(b)+3);
            r[0]=c; r[1]=0;
            strcat(r,a); strcat(r,b);
            stack[++top]=r;
        }
    }
    printf("%s\n", stack[top]);
    return 0;
}
