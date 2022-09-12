#include<stdio.h>
#include "stack_A.c"
#include<string.h>
#define SIZE 128

int main() {
    Stack* myStack = createStack(SIZE);
    char str[SIZE], ch;
    int i, len, flag = 1;
    printf("Enter a string: ");
    scanf("%s", str);
    len = strlen(str);
    for (i = 0; i < len/2; i++)
    {
        push(myStack, str[i]);
    }
    if (len%2)
        i++;
    while (str[i] != '\0' && flag)
    {
        pop(myStack, &ch);
        if(ch != str[i])
            flag = 0;
        i++;
    }
    if (flag)
        printf("Palindromic String\n");
    else
        printf("Non Palindromic String\n");
    destroyStack(myStack);
    return 0;   
}