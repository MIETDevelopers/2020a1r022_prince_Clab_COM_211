#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Stack
{
    char *array;
    int top;
    int maxSize;
};
    struct Stack *createStack(int maxSize)
    {
        struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
        stack->maxSize = maxSize;
        stack->top = -1;
        stack->array = (char *)malloc(stack->maxSize * sizeof(char));
        return stack;
    }
    int isFull(struct Stack *stack)
    {
        if (stack->top == stack->maxSize - 1)
        { // when top is equal to the last index, the stack is full
            return 1;
        }
        else
            return 0;
    }
    // isEmpty() for checking if the stack is empty
    int isEmpty(struct Stack *stack)
    {
        // when top is equal to -1, the stack is empty
        if (stack->top == -1)
        {
            return 1;
        }
        else
            return 0;
    }
    // push() for pushing an element in the stack.
    void push(struct Stack *stack, int element)
    {
        if (isFull(stack))
        { // calling the isFull() function to check if the stack is full
            printf("OVERFLOW !!! Stack is full! \n");
        }
        else
        {
            stack->array[++stack->top] = element; // incrementing top by 1
        }
    }
    // pop() for deleting/removing the top most element from the stack
    char pop(struct Stack *stack)
    {
        char elementRemoved;
        if (isEmpty(stack))
        {
            printf("Stack is Empty.\n");
            printf("**ERROR**\n");
            return '\0';
        }
        else
        {
            elementRemoved = stack->array[stack->top];
            stack->top--;
            return elementRemoved;
        }
    }
    // for displaying the elements present in the stack
    void displayElements(struct Stack *stack)
    {
        if (isEmpty(stack))
        {
            printf("Stack is empty! \n");
        }
        else
        {
            printf("Elements present in the stack are... \n");
            int temp;
            temp = stack->top;
            while (temp != -1)
            {
                printf("%d \n", stack->array[temp]);
                --temp;
            }
        }
    }
    int main()
    {
        struct Stack stack1;
        stack1.top = 0;
        char exp[100];
        int sizeOfExp;

        printf("Now enter expression:");
        scanf("%stack", exp);
        sizeOfExp = strlen(exp);
        stack1.array = (char *)malloc(sizeof(char) * sizeOfExp);
        stack1.maxSize = sizeOfExp;

        for (int i = 0; i < sizeOfExp; i++)
        {
            if (exp[i] == '{' || exp[i] == '[' || exp[i] == '(')
            {
                push(&stack1, exp[i]);
                continue;
            }
            if (exp[i] == '}' || exp[i] == ']' || exp[i] == ')')
            {
                if ((stack1.array[stack1.top] == '{' && exp[i] == '}') || (stack1.array[stack1.top] == '(' && exp[i] == ')') || (stack1.array[stack1.top] == '[' && exp[i] == ']'))
                {
                    pop(&stack1);
                }
                else
                {
                    printf("UNBALANCED\n");
                    return 0;
                }
            }
        }
        if (stack1.top == 0)
        {
            printf("BALANCED\n");
        }
        else
        {
            printf("UNBALANCED\n");
        }

        return 0;
    }
