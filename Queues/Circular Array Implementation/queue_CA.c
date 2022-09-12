#include<stdlib.h>
#include "queue_CA.h"

Queue* createQueue() {
    Queue* qptr = (Queue*)malloc(sizeof(Queue));
    qptr->front = 0;
    qptr->rear = -1;
    qptr->count = 0;
    qptr->data = (itemType*)malloc(sizeof(itemType) * MAX_SIZE);
    return qptr;
}

void destroyQueue(Queue* qptr) {
    free(qptr->data);
    free(qptr);
}

Bool isQueueEmpty(Queue* qptr) {
    return qptr->count == 0;
}

Bool isQueueFull(Queue* qptr) {
    return qptr->count == MAX_SIZE;
}

statusCode enqueue(Queue* qptr, itemType item) {
    statusCode ret_val = SUCCESS;
    if(isQueueFull(qptr))
        ret_val = FAILURE;
    else {
        qptr->data[(qptr->rear + 1) % MAX_SIZE] = item;
        qptr->rear = (qptr->rear + 1) % MAX_SIZE;
        qptr->count++;
    }
    return ret_val;
}

statusCode dequeue(Queue* qptr, itemType* item_ptr) {
    statusCode ret_val = SUCCESS;
    if(isQueueEmpty(qptr))
        ret_val = FAILURE;
    else {
        *item_ptr = qptr->data[qptr->front];
        qptr->front = (qptr->front + 1) % MAX_SIZE;
        qptr->count--;
    }
    return ret_val;
}

statusCode peekFront(Queue* qptr, itemType* item_ptr) {
    statusCode ret_val = SUCCESS;
    if(isQueueEmpty(qptr))
        ret_val = FAILURE;
    else
        *item_ptr =  qptr->data[qptr->front];
    return ret_val;
}

