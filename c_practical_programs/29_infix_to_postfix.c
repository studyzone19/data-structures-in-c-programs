/*
Infix to Postfix conversion (single-digit operands and +,-,*,/,^, parentheses)
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int prec(char c){
    if(c=='+'||c=='-') return 1;
    if(c=='*'||c=='/') return 2;
    if(c=='^') return 3;
    return 0;
}

int main(){
    char in[100], out[200], stack[100];
    int top=-1;
    scanf("%s", in);
    int k=0;
    for(int i=0; in[i]; i++){
        char c = in[i];
        if(isalnum(c)) out[k++]=c;
        else if(c=='(') stack[++top]=c;
        else if(c==')'){
            while(top!=-1 && stack[top]!='(') out[k++]=stack[top--];
            if(top!=-1 && stack[top]=='(') top--;
        } else {
            while(top!=-1 && ((prec(stack[top])>prec(c)) || (prec(stack[top])==prec(c) && c!='^')) && stack[top]!='(') out[k++]=stack[top--];
            stack[++top]=c;
        }
    }
    while(top!=-1) out[k++]=stack[top--];
    out[k]=0;
    printf("%s\n", out);
    return 0;
}
