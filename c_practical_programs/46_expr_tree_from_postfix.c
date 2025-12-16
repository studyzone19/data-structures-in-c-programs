/*
Expression tree from postfix: build tree and evaluate/inorder print
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct Node{ char data; struct Node *left,*right; } Node;
Node* newNode(char c){ Node* n=malloc(sizeof(Node)); n->data=c; n->left=n->right=NULL; return n; }

int isOperator(char c){ return c=='+'||c=='-'||c=='*'||c=='/'; }

int evaluate(Node* root){
    if(!root) return 0;
    if(!isOperator(root->data)) return root->data - '0';
    int l = evaluate(root->left);
    int r = evaluate(root->right);
    switch(root->data){
        case '+': return l+r;
        case '-': return l-r;
        case '*': return l*r;
        case '/': return l/r;
    }
    return 0;
}

int main(){
    char s[200]; scanf("%s", s);
    Node* stack[200]; int top=-1;
    for(int i=0;s[i];i++){
        char c=s[i];
        if(isdigit(c)) stack[++top]=newNode(c);
        else {
            Node* r=stack[top--]; Node* l=stack[top--];
            Node* n=newNode(c); n->left=l; n->right=r; stack[++top]=n;
        }
    }
    Node* root = stack[top];
    printf("Inorder: ");
    // inorder print
    void inorder(Node* r){ if(!r) return; inorder(r->left); printf("%c ", r->data); inorder(r->right); }
    inorder(root); printf("\n");
    printf("Evaluated: %d\n", evaluate(root));
    return 0;
}
