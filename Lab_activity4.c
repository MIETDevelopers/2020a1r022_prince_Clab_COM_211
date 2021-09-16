#include <stdio.h>
#include <string.h>
#include <ctype.h> // for using isdigit()
#include <stdlib.h>

struct Stack
{
    int top;
    int capacity;
    int *array;
};

// Stack Operations
struct Stack *createStack(int capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));

    if (!stack)
    {
        return NULL;
    }

    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));

    if (!stack->array)
    {
        return NULL;
    }

    return stack;
}

int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

char peek(struct Stack *stack)
{
    return stack->array[stack->top];
}

char pop(struct Stack *stack)
{
    if (!isEmpty(stack))
    {
        return stack->array[stack->top--];
    }
    return '\0';
}

void push(struct Stack *stack, char op)
{
    stack->array[++stack->top] = op;
}

// The main function that returns value of a given postfix expression
int evaluatePostfix(char *exp)
{
    // Create a stack of capacity equal to expression size
    struct Stack *stack = createStack(strlen(exp));
    int i;

    // See if stack was created successfully
    if (!stack)
    {
        return -1;
    }

    // Scan all characters one by one
    for (i = 0; exp[i]; ++i)
    {
        // If the scanned character is an operand (number here),
        // push it to the stack.
        if (isdigit(exp[i]))
        {
            push(stack, exp[i] - '0');
        }

        // If the scanned character is an operator, pop two
        // elements from stack apply the operator
        else
        {
            int val1 = pop(stack);
            int val2 = pop(stack);
            switch (exp[i])
            {
            case '+':
                push(stack, val2 + val1);
                break;
            case '-':
                push(stack, val2 - val1);
                break;
            case '*':
                push(stack, val2 * val1);
                break;
            case '/':
                push(stack, val2 / val1);
                break;
            }
        }
    }
    return pop(stack);
}
int evaluatePrefix(char *prefix)
{
    int a, b, temp, result;
    struct Stack *stack = createStack(strlen(prefix));
    int i;

    for (i = strlen(prefix) - 1; i >= 0; i--)
    {
        if (isdigit(prefix[i]))
        {
            push(stack, prefix[i] - 48);
        }
        else
        {
            b = pop(stack);
            a = pop(stack);
            switch (prefix[i])
            {
            case '+':
                temp = b + a;
                break;
            case '-':
                temp = b - a;
                break;
            case '*':
                temp = b * a;
                break;
            case '/':
                temp = b / a;
                break;
            case '%':
                temp = b % a;
                break;
            }
            push(stack, temp);
        }
    }
    result = pop(stack);
    return result;
}

int value(char c)
{
    return (c - '0');
}

int evaluateInfix(char *exp)
{
    // Base Case: Given expression is empty
    if (*exp == '\0')
    {
        return -1;
    }

    // The first character must be an operand, find its value
    int res = value(exp[0]);

    // Traverse the remaining characters in pairs
    for (int i = 1; exp[i]; i += 2)
    {
        // The next character must be an operator, and
        // next to next an operand
        char opr = exp[i], opd = exp[i + 1];

        // If next to next character is not an operand
        if (!isdigit(opd))
            return -1;

        // Update result according to the operator
        if (opr == '+')
        {
            res += value(opd);
        }
        else if (opr == '-')
        {
            res -= value(opd);
        }
        else if (opr == '*')
        {
            res *= value(opd);
        }
        else if (opr == '/')
        {
            res /= value(opd);
        }

        // If not a valid operator
        else
        {
            return -1;
        }
    }
    return res;
}
int main()
{
    int choice;
    char exp[100];

    do
    {
        printf("\nEnter the operation you want to perform\n\nPress 1 for evaluating the prefix expression\n\nPress 2 for evaluating the postfix expression\n\nPress 3 for evaluating the infix expression\n\nPress 4 for quitting the program\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the prefix expression\n");
            scanf("%s", &exp);
            printf("Prefix evaluation: %d\n", evaluatePrefix(exp));
            break;
        case 2:
            printf("Enter the expression\n");
            scanf("%s", &exp);
            printf("Postfix evaluation: %d\n", evaluatePostfix(exp));
            break;
        case 3:
            printf("Enter the infix expression\n");
            scanf("%s", &exp);
            printf("Infix evaluation: %d\n", evaluateInfix(exp));
            break;
        case 4:
            printf("Quitting the program\n");
            break;

        default:
            printf("Enter from the above options\n");
            break;
        }
    } while (choice != 4);

    return 0;
}