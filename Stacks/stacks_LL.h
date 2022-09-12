#ifndef STACKS_LL_H
#define STACKS_LL_H

typedef enum {FALSE, TRUE} Bool;
typedef enum {FAILURE, SUCCESS} statusCode;
typedef int itemType;

typedef struct Node_tag {
    itemType data;
    struct Node_tag* next;
}Node;

typedef struct {
    Node* top;
}Stack;

//Operations on Stack

//Returns pointer to a created stack
Stack* createStack();

//Destroys a created stack and free's the memory allocated for that stack
void destroyStack(Stack*);

//Pushes given element to the stack and return status code (0 for FAILURE and 1 for SUCCESS)
statusCode push(Stack*, itemType);

// Pops top most element of the stack and stores in variable which the 2nd parameter is pointing to and return status code (0 for FAILURE anfd 1 for SUCCESS)
statusCode pop(Stack*, itemType*);

// Peeks the top most element and stores its value in variable which the 2nd parameter is pointing to and return status code (0 for FAILURE anfd 1 for SUCCESS)
statusCode peek(Stack*, itemType*);

//Assumes stack cannot be full as elements can always be pushed and allocated in the heap, thus always return FALSE(0). In case of push() error, status code 0 will be returned by push().
Bool isStackFull(Stack*);
//Checks if stack is empty and returns bool value (0 for FALSE and 1 for TRUE)
Bool isStackEmpty(Stack*);

#endif