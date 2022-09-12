#include<stdio.h>
#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE], result[MAX_SIZE], stack[MAX_SIZE], n, top;
    top = -1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        while (top != -1 && stack[top] >= arr[i])
        {
            top--;
        }
        if (top == -1)
        {
            result[i] = -1;
        }
        else
        {
            result[i] = stack[top];
        }
        top++;
        stack[top] = arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", result[i]);
    }
    printf("\n");
    return 0;
}