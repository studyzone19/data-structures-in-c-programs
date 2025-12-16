/*
Prefix to Postfix conversion
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
    char s[200]; scanf("%s", s);
    char *stack[200]; int top=-1;
    int n=strlen(s);
    for(int i=n-1;i>=0;i--){
        char c=s[i];
        if(isalnum(c)){
            char *t=malloc(2); t[0]=c; t[1]=0; stack[++top]=t;
        } else {
            char *a=stack[top--]; char *b=stack[top--];
            char *r=malloc(strlen(a)+strlen(b)+2);
            strcpy(r,a); strcat(r,b); int len=strlen(r); r[len]=c; r[len+1]=0;
            stack[++top]=r;
        }
    }
    printf("%s\n", stack[top]);
    return 0;
}
