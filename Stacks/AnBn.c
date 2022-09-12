#include<stdio.h>
#include "stack.c"
#define SIZE 128

Bool isAnBn(char*);

int main() {
    char str[SIZE];
    printf("Enter a string with only 'A' and 'B': ");
    scanf("%s", str);
    if(isAnBn(str))
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}

Bool isAnBn(char* str) {
    Stack* myStack = createStack(SIZE);
    int i = 0; char ch;
    Bool ret_val = FALSE;
    while(str[i] == 'A') {
        push(myStack, str[i]);
        i++;
    }
    while(!isStackEmpty(myStack) && str[i] == 'B') {
        pop(myStack, &ch);
        i++;
    }
    if(isStackEmpty(myStack) && str[i] == '\0')
        ret_val = TRUE;
    destroyStack(myStack);
    return ret_val;
}