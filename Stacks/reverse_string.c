#include<stdio.h>
#include "stack_A.c"
#define SIZE 128

int main()
{
    char str[SIZE]; int i = 0;
    Stack* myStack = createStack(SIZE);
    printf("Enter a string: ");
    scanf("%s", str);
    printf("Entered string: ");
    for (int i = 0; str[i] != '\0'; i++)
    {
        printf("%c", str[i]);
    }
    printf("\n");
    push(myStack, 20);
    for (i = 0; str[i] != '\0'; i++)
    {
        push(myStack, str[i]);
    }
    i = 0;
    while (!isStackEmpty(myStack))
    {
        pop(myStack, &str[i]);
        i++;
    }
    printf("Reversed string: ");
    for (i = 0; str[i] != '\0'; i++)
    {
        printf("%c", str[i]);
    }
    printf("\n");
    destroyStack(myStack);
    return 0;    
}