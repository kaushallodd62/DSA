#include<stdio.h>
#include "stack.c"
#define SIZE 128

Bool AnBnCn(char*);
int main() {
    char str[SIZE];
    printf("Enter a string with only 'A', 'B' and 'C': ");
    scanf("%s", str);
    if(AnBnCn(str))
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}

Bool AnBnCn(char* str) {
    Stack* myStack = createStack(SIZE);
    int i = 0; char ch;
    Bool ret_val = FALSE;
    
}