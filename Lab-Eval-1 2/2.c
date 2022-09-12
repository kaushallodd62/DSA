#include <stdio.h>
#define SIZE 10 

int q[SIZE], front = -1, rear = -1;

void enqueue(int value) 
{
    if (rear == SIZE - 1)
        printf("\nQueue is Full!!");
    else {
        if (front == -1)
            front = 0;
        rear++;
        q[rear] = value;
    }
}

void dequeue() {
    if (front == -1)
        printf("\nQueue is Empty!!");
    else 
    {
        printf("\nDeleted : %d", q[front]);
        front++;
        if (front > rear)
        front = rear = -1;
    }
}

// Function to print the queue
void Front() 
{
    if (rear == -1)
        printf("\nQueue is Empty!!!");
    else 
        printf("Front element is : %d",q[front]);
}

//Function to return the count
int count()
{
    return rear-front;
}

//function to reorder the queue
void reorder(int k,int arr[],int n)
{
    int temp;
    for(int i=k-1;i>=0;i--)
    {
        enqueue(arr[i]);
    }
    for(int i=k;i<n;i++)
        enqueue(arr[i]);
}

//function to display the whole queue
void display() 
{
    if (rear == -1)
        printf("\nQueue is Empty!!!");
    else 
    {
        int i;
        printf("\nQueue elements are:\n");
        for (i = front; i <= rear; i++)
            printf("%d  ", q[i]);
    }
    printf("\n");
}
int main()
{
    int n, arr[SIZE], k;
    printf("Enter number of elements : ");
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter k :");
    scanf("%d",&k);
    reorder(k, arr, n);
    display();
	return 0;
}