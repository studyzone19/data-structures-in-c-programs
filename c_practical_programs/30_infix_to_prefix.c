/*
Infix to Prefix: reverse string, change parentheses, use postfix on reversed, then reverse result.
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void reverse(char *s){
    int i=0,j=strlen(s)-1; while(i<j){ char t=s[i]; s[i]=s[j]; s[j]=t; i++; j--; }
}
int prec(char c){
    if(c=='+'||c=='-') return 1;
    if(c=='*'||c=='/') return 2;
    if(c=='^') return 3;
    return 0;
}

int main(){
    char in[100]; scanf("%s", in);
    reverse(in);
    for(int i=0; in[i]; i++){ if(in[i]=='(') in[i]=')'; else if(in[i]==')') in[i]='('; }
    // now get postfix of modified string
    char out[200], stack[100]; int top=-1, k=0;
    for(int i=0; in[i]; i++){
        char c=in[i];
        if(isalnum(c)) out[k++]=c;
        else if(c=='(') stack[++top]=c;
        else if(c==')'){ while(top!=-1 && stack[top]!='(') out[k++]=stack[top--]; if(top!=-1) top--; }
        else {
            while(top!=-1 && ((prec(stack[top])>prec(c)) || (prec(stack[top])==prec(c) && c!='^')) && stack[top]!='(') out[k++]=stack[top--];
            stack[++top]=c;
        }
    }
    while(top!=-1) out[k++]=stack[top--];
    out[k]=0;
    reverse(out);
    printf("%s\n", out);
    return 0;
}
