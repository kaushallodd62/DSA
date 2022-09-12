#ifndef QUEUES_LL_H
#define QUEUES_LL_H

typedef enum {FAILURE, SUCCESS} statusCode;
typedef enum {FALSE, TRUE} Bool;
typedef int itemType;

//Queues implementation using singly linked lists.
typedef struct Node_tag {
    itemType data;
    struct Node_tag* next;
} Node;

typedef struct Queue_tag {
    Node *front, *rear;
}Queue;

//Operations on Queues

//Creates/Initializes Queue and returns pointer to that Queue.
Queue* createQueue();

//Destroys a created Queue and free's the memory allocated for that Queue
void destroyQueue(Queue*);

//Inserts/enQueue() given element to the rear end of the Queue. Returns status code (0 for FAILURE and 1 for SUCCESS)
statusCode enqueue(Queue*, itemType);

//Deletes/deQueue() the element from the front end of the Queue and stores it in the variable which the 2nd parameter is pointing to. Returns status code (0 for FAILURE anfd 1 for SUCCESS)
statusCode dequeue(Queue*, itemType*);

//Peeks the top most element and stores its value in variable which the 2nd parameter is pointing to. Return status code (0 for FAILURE anfd 1 for SUCCESS)
statusCode peekFront(Queue*, itemType*);

//Traverses the queue and prints all elements on the queue/
void printQueue(Queue*);

//Assumes queue cannot be full as elements can always be enqueued and allocated in the heap, thus always return FALSE(0). In case of enqueue() error, status code 0 will be returned by enqueue().
Bool isQueueFull(Queue*);
//Checks if Queue is empty and returns bool value (0 for FALSE and 1 for TRUE)
Bool isQueueEmpty(Queue*);


#endif