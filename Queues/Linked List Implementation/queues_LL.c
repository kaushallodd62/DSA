#include<stdlib.h>
#include "queues_LL.h"

Queue* createQueue() {
    Queue* qptr = (Queue*)malloc(sizeof(Queue));
    qptr->front = NULL;
    qptr->rear = NULL;
    return qptr;
}

void destroyQueue(Queue* qptr) {
    Node *lptr = qptr->front, *nptr;
    nptr = lptr;
    while(lptr != NULL) {
        lptr = lptr->next;
        free(nptr);
        nptr = lptr;
    }
    free(qptr);
}

statusCode enqueue(Queue* qptr, itemType item) {
    statusCode ret_val = FAILURE;
    Node* nptr = (Node*)malloc(sizeof(Node));
    if(nptr != NULL) {
        nptr->data = item;
        nptr->next = NULL;
        if(isQueueEmpty(qptr))
            qptr->front = qptr->rear = nptr;
        else {
            qptr->rear->next = nptr;
            qptr->rear = nptr;
        }
        ret_val = SUCCESS;
    }
    return ret_val;
}

statusCode dequeue(Queue* qptr, itemType* iptr) {
    statusCode ret_val = FAILURE;
    if(!isQueueEmpty(qptr)) {
        Node* nptr = qptr->front;
        *iptr = nptr->data;
        if(nptr->next == NULL)
            qptr->front = qptr->rear = NULL;
        else
            qptr->front = nptr->next;
        free(nptr);
        ret_val = SUCCESS; 
    }
    return ret_val;
}

statusCode peekFront(Queue* qptr, itemType* iptr) {
    statusCode ret_val = FAILURE;
    if(!isQueueEmpty(qptr)) {
        *iptr = qptr->front->data;
        ret_val = SUCCESS; 
    }
    return ret_val;
}

void printQueue(Queue* qptr) {
    if(!isQueueEmpty(qptr)) {
        Node* nptr = qptr->front;
        printf("{");
        while(nptr->next != NULL) {
            printf("%d, ", nptr->data);
            nptr = nptr->next;
        }
        printf("%d}\n", nptr->data);
    }
    else
        printf("Queue is Empty!\n");
    return ;
}

Bool isQueueEmpty(Queue* qptr) {
    return qptr->front == NULL && qptr->rear == NULL;
}

Bool isQueueFull(Queue* qptr) {
    return FALSE;
}