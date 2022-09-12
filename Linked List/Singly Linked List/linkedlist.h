#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H


typedef enum {FAILURE, SUCCESS} statusCode;
typedef enum {FALSE, TRUE} Bool;
typedef int itemType;

typedef struct Node_tag{
    itemType data;
    struct Node_tag* next;
    Node_tag() {
        next = __null;
    }
    Node_tag(int val) {
        data = val;
        next = __null;
    }
}Node;

//Inserts a node at the start of the linked list and returns status code (1 for SUCCESS and 0 for FAILURE).
statusCode insertNodeAtStart(Node**, itemType);
//Deletes a node at the start of the linked list and returns status code (1 for SUCCESS and 0 for FAILURE).
statusCode deleteNodeAtStart(Node**, itemType*);

//Inserts a node at the end of the linked list and returns status code (1 for SUCCESS and 0 for FAILURE).
statusCode insertNodeAtEnd(Node**, itemType);
//Deletes a node at the end of the linked list and returns status code (1 for SUCCESS and 0 for FAILURE).
statusCode deleteNodeAtEnd(Node**, itemType*);

//Prints all nodes in the linked list.
void printList(Node*);

//Deletes the whole list by freeing up the memory allocated for each node.
void deleteList(Node*);


#endif