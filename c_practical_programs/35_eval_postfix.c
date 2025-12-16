/*
Evaluate postfix expression (single-digit operands)
*/
#include <stdio.h>
#include <ctype.h>

int main(){
    char s[200]; scanf("%s", s);
    int stack[200], top=-1;
    for(int i=0;s[i];i++){
        char c=s[i];
        if(isdigit(c)) stack[++top]=c-'0';
        else {
            int b=stack[top--]; int a=stack[top--]; int res=0;
            if(c=='+') res=a+b;
            else if(c=='-') res=a-b;
            else if(c=='*') res=a*b;
            else if(c=='/') res=a/b;
            stack[++top]=res;
        }
    }
    printf("%d\n", stack[top]);
    return 0;
}
