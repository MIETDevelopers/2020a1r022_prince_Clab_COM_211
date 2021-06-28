#include <stdio.h>
#include <stdlib.h> // for dynamic memory allocation and exit()
#include <conio.h>  // for getch()
// Structure representing stack
struct Stack
{
    int *array;  // in this we stores the elements in the stack
    int top;     // index of the top element
    int maxSize; // Maximum size of the stack
};
// For creating the stack and allocating the memory
struct Stack *createStack(int maxSize)
{
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    s->maxSize = maxSize;
    s->top = -1; // initialization to -1 shows that the stack is empty
    s->array = (int *)malloc(s->maxSize * sizeof(int));
    return s;
}
// isFull() for checking if the stack is full
int isFull(struct Stack *s)
{
    if (s->top == s->maxSize - 1)
    { // when top is equal to the last index, the stack is full
        return 1;
    }
    else
        return 0;
}
// isEmpty() for checking if the stack is empty
int isEmpty(struct Stack *s)
{
    // when top is equal to -1, the stack is empty
    if (s->top == -1)
    {
        return 1;
    }
    else
        return 0;
}
// push() for pushing an element in the stack.
void push(struct Stack *s, int element)
{
    if (isFull(s))
    { // calling the isFull() function to check if the stack is full
        printf("OVERFLOW !!! Stack is full! \n");
    }
    else
    {
        s->array[++s->top] = element; // incrementing top by 1
        printf("%d pushed to stack\n", element);
    }
}
// pop() for deleting/removing the top most element from the stack
int pop(struct Stack *s)
{
    if (isEmpty(s))
    { // calling the isEmpty() function to check if the stack is empty
        return 0;
    }
    else
        return s->array[s->top--]; // decrementing top by 1
}
// for displaying the elements present in the stack
void displayElements(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty! \n");
    }
    else
    {
        printf("Elements present in the stack are... \n");
        int temp;
        temp = s->top;
        while (temp != -1)
        {
            printf("%d \n", s->array[temp]);
            --temp;
        }
    }
}
int main()
{
    printf("\t\t STACK IMPLEMENTATION \n");
    int choice, element, popped, maxSize;
    printf("Enter the size of the stack : ");
    scanf("%d", &maxSize);
    struct Stack *s = createStack(maxSize); // calling the createStack() function
    do
    {
        printf("\t OPERATIONS \n");
        printf(" 1. Push \n 2. Pop \n 3. Display elements \n 4. Exit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice); // input choice from the user
        switch (choice)
        {
        case 1:
            printf("\n \t Pushing in stack \n");
            printf("Enter the element you want to push in the stack : ");
            scanf("%d", &element);
            push(s, element); // calling the push function
            break;
        case 2:
            printf("\n \t Popping from stack \n");
            popped = pop(s); // calling the pop function
            if (s->top == -1 && popped == 0)
            {
                // s->top is -1 which means the stack is empty
                printf("UNDERFLOW!!! Stack is empty! \n");
            }
            else
                printf("%d popped from the stack \n", popped);
            break;
        case 3:
            displayElements(s); // calling the display function
            break;
        case 4:
            exit(0);
        default:
            printf("\n \t WRONG CHOICE ENTERED !! \n");
            break;
        }
        printf("Press enter to continue... \n");
        getch();
    } while (1);
    return 0;
}