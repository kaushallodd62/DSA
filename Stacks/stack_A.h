#ifndef _STACK_H
#define _STACK_H

typedef enum {FALSE, TRUE} Bool;
typedef enum {FAILURE, SUCCESS} statusCode;
typedef char itemType;

typedef struct {
    int top;
    unsigned int size;
    itemType* data;
}Stack;

//Operations on Stack

//Returns pointer to a created stack of given capacity
Stack* createStack(unsigned int);

//Destroys a created stack and free's the memory allocated for that stack
void destroyStack(Stack*);

//Pushes given element to the stack and return status code (0 for FAILURE and 1 for SUCCESS)
statusCode push(Stack*, itemType);

// Pops top most element of the stack and stores in variable which the 2nd parameter is pointing to and return status code (0 for FAILURE anfd 1 for SUCCESS)
statusCode pop(Stack*, itemType*);

// Peeks the top most element and stores its value in variable which the 2nd parameter is pointing to and return status code (0 for FAILURE anfd 1 for SUCCESS)
statusCode peek(Stack*, itemType*);

//Checks if stack is full and returns bool value (0 for FALSE and 1 for TRUE)
Bool isStackFull(Stack*);
//Checks if stack is empty and returns bool value (0 for FALSE and 1 for TRUE)
Bool isStackEmpty(Stack*);

#endif