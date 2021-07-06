#include <stdio.h>
#include <stdlib.h>     // for dynamic memory allocation and exit()
#include <string.h>     
// Structure representing Stack
struct Stack
{
    char *array;     // stores the elements in the Stack
    int top;         // index of the top element
    int Size;        // Max Size of the Stack 
};
// isFull() for checking if the Stack is full
int isFull(struct Stack *s)
{
    if (s->top == s->Size - 1)    // when top is equal to the last index, the Stack is full
    {
        return 1;
    }
    else
        return 0;
}
// isEmpty() for checking if the Stack is empty
int isEmpty(struct Stack *s)
{          // when top is equal to -1, the Stack is empty
    if (s->top == -1)
    {
        return 1;
    }
    else
        return 0;
}        
// push() for pushing an element in the Stack.
void push(struct Stack *s, char ch)
{
    if (isFull(s))                        // calling the isFull() function to check if the Stack is full
    {
       printf("Stack Overflow!!\n");
    }
    s->array[++s->top] = ch;
}
// pop() for deleting/removing the top most element from the Stack
int pop(struct Stack *s)
{
    char elremoved;
    if (isEmpty(s))                   // calling the isEmpty() function to check if the Stack is empty
    {
        printf("Stack is empty!!!\n");
        printf("ERROR!!\n");
        return('\0');
    }
    else{
        elremoved = s->array[s->top];
        s->top--;
        return elremoved;
    }
    
}
int main()
{
    int expSize, i, popped;
    char exp[30];
    struct Stack s;
    s.top = -1;                    
    
    printf("Enter the expression : \n");
    gets(exp);                   
    expSize = strlen(exp);    
    s.Size = expSize;       
    s.array = (char *)malloc(s.Size * sizeof(char));    //allocating the dynamic maemory allocation
    for (i = 0; i < expSize; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(&s, exp[i]);                  //calling the push function
        }
        if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if ((s.array[s.top] == '(' && exp[i] == ')') || (s.array[s.top] == '{' && exp[i] == '}') || (s.array[s.top] == '[' && exp[i] == ']'))  //Thank you Aditya Kotwal for this part
            {
                popped = pop(&s);   //calling the pop function
            }
            else
            {
                printf("This expression is NOT BALANCED!!! \n");
                return 0;
            }    
        }
    }
    if (isEmpty(&s))
    {
        printf(" This expression is BALANCED!! \n");
    }
    else
    {
        printf("This expression is NOT BALANCED!! \n");
    }
    return 0;