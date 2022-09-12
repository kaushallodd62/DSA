#include<stdlib.h>
#include "stack_A.h"

Stack* createStack(unsigned int capacity) {
    Stack* stck_ptr = (Stack*)malloc(sizeof(Stack));
    stck_ptr -> top = -1;
    stck_ptr -> size = capacity;
    stck_ptr -> data = (itemType*)malloc(sizeof(itemType) * capacity);
    return stck_ptr;
}

void destroyStack(Stack* stck_ptr) {
    free(stck_ptr -> data);
    free(stck_ptr);
}

statusCode push(Stack* stck_ptr, itemType item) {
    statusCode ret_val = SUCCESS;
    if(isStackFull(stck_ptr))
        ret_val = FAILURE;
    else 
        stck_ptr -> data[++(stck_ptr -> top)] = item;
    return ret_val;
}

statusCode pop(Stack* stck_ptr, itemType* item_ptr) {
    statusCode ret_val = SUCCESS;
    if(isStackEmpty(stck_ptr))
        ret_val = FAILURE;
    else
        *item_ptr = stck_ptr -> data[(stck_ptr -> top)--];
    return ret_val;
}

statusCode peek(Stack* stck_ptr, itemType* item_ptr) {
    statusCode ret_val = SUCCESS;
    if(isStackEmpty(stck_ptr))
        ret_val = FAILURE;
    else
        *item_ptr = stck_ptr -> data[stck_ptr -> top];
    return ret_val;
}

Bool isStackEmpty(Stack* stck_ptr) {
    return stck_ptr -> top == -1;
}

Bool isStackFull(Stack* stck_ptr) {
    return stck_ptr -> top == stck_ptr -> size - 1;
}

