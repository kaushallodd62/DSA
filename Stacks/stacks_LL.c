#include<stdlib.h>
#include "stacks_LL.h"

Stack* createStack() {
    Stack* stck_ptr = (Stack*)malloc(sizeof(Stack));
    stck_ptr->top = NULL;
    return stck_ptr;
}

void destroyStack(Stack* stck_ptr) {
    if(!isStackEmpty(stck_ptr)) {
        Node* nptr = stck_ptr->top;
        while(nptr != NULL) {
            stck_ptr->top = nptr->next;
            free(nptr);
            nptr = stck_ptr->top;
        }
    }
    free(stck_ptr);
}

statusCode push(Stack* stck_ptr, itemType item) {
    statusCode ret_val = FAILURE;
    Node* nptr = (Node*)malloc(sizeof(Node));
    if(nptr != NULL) {
        nptr->data = item;
        nptr->next = stck_ptr->top;
        stck_ptr->top = nptr;
        ret_val = SUCCESS;
    }
    return ret_val;
}

statusCode pop(Stack* stck_ptr, itemType* iptr) {
    statusCode ret_val = FAILURE;
    if(!isStackEmpty(stck_ptr)) {
        Node* nptr = stck_ptr->top;
        *iptr = nptr->data;
        stck_ptr->top = nptr->next;
        free(nptr);
        ret_val = SUCCESS;
    }
    return ret_val;
}

statusCode peek(Stack* stck_ptr, itemType* iptr) {
    statusCode ret_val = FAILURE;
    if(!isStackEmpty(stck_ptr)) {
        *iptr = stck_ptr->top->data;
        ret_val = SUCCESS;
    }
    return ret_val;
}

Bool isStackEmpty(Stack* stck_ptr) {
    return stck_ptr->top == NULL;
}

Bool isStackFull(Stack* stck_ptr) {
    return FALSE;
}