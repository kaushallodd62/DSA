#include<stdio.h>
#include "stacks_LL.c"

int main() {
    Stack* sptr = createStack();
    statusCode sc;
    sc = push(sptr, 4);
    if (sc == FAILURE)
        printf("Stack Full\n");
    else 
        printf("4 pushed to stack\n");
    sc = push(sptr, 10);
    if (sc == FAILURE)
        printf("Stack Full\n");
    else 
        printf("10 pushed to stack\n");
    sc = push(sptr, -5);
    if (sc == FAILURE)
        printf("Stack Full\n");
    else 
        printf("-5 pushed to stack\n");
    itemType var;
    sc = pop(sptr, &var);
    if (sc == FAILURE)
        printf("Stack Empty\n");
    else 
        printf("%d popped from stack\n", var);
    peek(sptr, &var);
    printf("%d peeked from the stack\n", var);
    sc = push(sptr, 6);
    if (sc == FAILURE)
        printf("Stack Full\n");
    else 
        printf("6 pushed to stack\n");
    sc = push(sptr, 9);
    if (sc == FAILURE)
        printf("Stack Full\n");
    else 
        printf("9 pushed to stack\n");
    sc = push(sptr, 69);
    if (sc == FAILURE)
        printf("Stack Full\n");
    else 
        printf("69 pushed to stack\n");
    sc = push(sptr, 22);
    if (sc == FAILURE)
        printf("Stack Full\n");
    else 
        printf("22 pushed to stack\n");
    sc = pop(sptr, &var);
    if (sc == FAILURE)
        printf("Stack Empty\n");
    else 
        printf("%d popped from stack\n", var);
    sc = pop(sptr, &var);
    if (sc == FAILURE)
        printf("Stack Empty\n");
    else 
        printf("%d popped from stack\n", var);
    sc = pop(sptr, &var);
    if (sc == FAILURE)
        printf("Stack Empty\n");
    else 
        printf("%d popped from stack\n", var);
    sc = pop(sptr, &var);
    if (sc == FAILURE)
        printf("Stack Empty\n");
    else 
        printf("%d popped from stack\n", var);
    sc = pop(sptr, &var);
    if (sc == FAILURE)
        printf("Stack Empty\n");
    else 
        printf("%d popped from stack\n", var);
    sc = pop(sptr, &var);
    if (sc == FAILURE)
        printf("Stack Empty\n");
    else 
        printf("%d popped from stack\n", var);
    sc = pop(sptr, &var);
    if (sc == FAILURE)
        printf("Stack Empty\n");
    else 
        printf("%d popped from stack\n", var);
    sc = pop(sptr, &var);
    if (sc == FAILURE)
        printf("Stack Empty\n");
    else 
        printf("%d popped from stack\n", var);
    destroyStack(sptr);
    return 0;
    
}