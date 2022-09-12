#include<stdio.h>
#include "stack.c"
#define SIZE 128

Bool isBalancedParenthesis(char* str) {
    Stack* myStack = createStack(SIZE);
    int i; char ch;
    Bool ret_val = TRUE;
    statusCode sc = SUCCESS;
    while (str[i] != '\0' && ret_val == TRUE) {
        if(str[i] == '(')
            push(myStack, str[i]);
        else if(str[i] == ')') {
            sc = pop(myStack, &ch);
            if(sc == FAILURE)
                ret_val = FALSE;
        }
        i++;
    }
    if(ret_val == TRUE && !isStackEmpty(myStack))
        ret_val = FALSE;
    destroyStack(myStack);
    return ret_val;
}

int main() {
    char str[SIZE];
    printf("Enter string to check for balanced parenthesis: ");
    scanf("%s", str);
    if(isBalancedParenthesis(str))
        printf("Equation has balanced parenthesis\n");
    else
        printf("Parenthesis are not balanced\n");
    return 0;
}