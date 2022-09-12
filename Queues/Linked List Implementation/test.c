#include<stdio.h>
#include "queues_LL.c"


int main()  { 
    statusCode sc; itemType x;
    Queue* myQ = createQueue(); 
 
    // inserting elements in the queue 
    sc = enqueue(myQ, 10);
    if(sc == FAILURE)
        printf("Queue Full!\n");
    else
        printf("10 inserted to the Queue\n");

    sc = dequeue(myQ, &x);
    if (sc == FAILURE)
        printf("Queue Empty!\n");
    else
        printf("%d deleted from the Queue\n", x);
    sc = enqueue(myQ, 20);
    if(sc == FAILURE)
        printf("Queue Full!\n");
    else
        printf("20 inserted to the Queue\n");
    sc = enqueue(myQ, 30);
    if(sc == FAILURE)
        printf("Queue Full!\n");
    else
        printf("30 inserted to the Queue\n");
    sc = enqueue(myQ, 40);
    if(sc == FAILURE)
        printf("Queue Full!\n");
    else
        printf("40 inserted to the Queue\n");
    sc = enqueue(myQ, 50);
    if(sc == FAILURE)
        printf("Queue Full!\n"); 
    else
        printf("50 inserted to the Queue\n");

    printQueue(myQ);    
    sc = dequeue(myQ, &x);
    if (sc == FAILURE)
        printf("Queue Empty!\n");
    else
        printf("%d deleted from the Queue\n", x);
    sc = dequeue(myQ, &x);
    if (sc == FAILURE)
        printf("Queue Empty!\n");
    else
        printf("%d deleted from the Queue\n", x);
    
    sc = peekFront(myQ, &x);
    if (sc == FAILURE)
        printf("Queue Empty!\n");
    else
        printf("%d peeked from the Queue\n", x);
    sc = dequeue(myQ, &x);
    if (sc == FAILURE)
        printf("Queue Empty!\n");
    else
        printf("%d deleted from the Queue\n", x);
    
    sc = dequeue(myQ, &x);
    if (sc == FAILURE)
        printf("Queue Empty!\n");
    else
        printf("%d deleted from the Queue\n", x);
    
    sc = enqueue(myQ, 40);
    if(sc == FAILURE)
        printf("Queue Full!\n");
    else
        printf("40 inserted to the Queue\n");
    sc = dequeue(myQ, &x);
    if (sc == FAILURE)
        printf("Queue Empty!\n");
    else
        printf("%d deleted from the Queue\n", x);
    printf("%d\n", isQueueEmpty(myQ));
    printf("%d\n", isQueueFull(myQ));
    destroyQueue(myQ);
    return 0; 
} 