#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <conio.h>
struct Queue
{
    int *data;       //the array which has items
    int maxCapacity; // maxCapacity is allocated at the time of creation of the queue
    // if number of elements = maxCapacity, the queue is full
    int front; //index of the front item, starts from 0
    int rear;  //index of the rear item, starts from 0
};

int noOfItems(struct Queue *queue)
{
    // printf("calculating noOfItems...\n");
    if (queue->rear == -1 && queue->front == -1)
    {
        return 0;
    }
    else if (queue->rear >= queue->front)
    {
        return (queue->rear - queue->front) + 1;
    }
    else
    {
        return ((queue->maxCapacity) - queue->front) + (queue->rear + 1);
    }
}

int isFull(struct Queue *queue)
{
    // input: the address of the queue
    // output: 1 if full, 0 if not full
    // it checks if the queue is full or not
    if (noOfItems(queue) == queue->maxCapacity)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int enQueue(struct Queue *queue, int item)
{
    // input: the address of the queue, item
    // output: 1 if inserted, 0 if not inserted
    // it checks if the queue is full or not
    // increments the rear (circularly) and it adds one element at the rear
    // printf("noOfItems = %d", noOfItems(queue));
    printf("enQueue %d:\n", item);
    if (isFull(queue) == 0)
    {
        
        if (noOfItems(queue) == 0)
        {
            // printf("empty\n");
            // queue->front = -1 as the queue is empty
            // we have to make it 0 as now we will insert an item
            queue->front = 0;
        }
        queue->rear = (queue->rear + 1) % (queue->maxCapacity); // incrementing the rear circularly
        queue->data[queue->rear] = item;
        return 1;
    }
    else
    {
        return 0;
    }
}

int deQueue(struct Queue *queue)
{
    // input: the address of the queue
    // output: the item removed, NULL if the queue is empty
    // check if the queue is empty
    printf("\n\tinside deQueue function...\n");
    if (noOfItems(queue) != 0)
    {
        // copy the front item in a variable (temp)
        int temp = queue->data[queue->front];
        // increment front
        // some change here is needed
        if (queue->front == queue->rear)
        {
            // the front should never cross the rear
            // it means that the queue is going to become empty after this deQueue operation
            queue->front = -1;
            queue->rear = -1;
        }
        else
        {
            queue->front = (queue->front + 1) % (queue->maxCapacity); //circular way
        }
        // return the variable (temp)
        return temp;
    }
    else
    {
        return INT_MIN;
    }
}

void printQueueDetails(struct Queue *queue)
{
    printf("maxCapacity=%d\t  front=%d\t  rear=%d\t \n", queue->maxCapacity, queue->front, queue->rear);
}

void printQueue(struct Queue *queue)
{
    int i;
    printf("queue: ");
    i = queue->front;
    if (noOfItems(queue) != 0)
    {
       
        do
        {
            printf("data[%d]= %d   ", i, queue->data[i]);
            i = (i + 1) % (queue->maxCapacity);
        } while (i != (queue->rear + 1) % queue->maxCapacity);
        printf("\n");
    }
}

int main()
{
    struct Queue queueA;
    int maxSpace, choice, element, deQueued, value;
    printf("Enter the size of the queue : ");
    scanf("%d", &maxSpace);
    queueA.maxCapacity = maxSpace;
    queueA.front = -1;                                             // the queue is empty
    queueA.rear = -1;                                              // the queue is empty
    queueA.data = (int *)malloc(queueA.maxCapacity * sizeof(int)); //memory allocation for the queue
    printf("noOfItems = %d", noOfItems(&queueA));
    do
    {
        printf("\t OPERATIONS \n");
        printf(" 1. enQueue \n 2. deQueue \n 3. Display elements \n 4. Exit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice); // input choice from the user
        switch (choice)
        {
        case 1:
            printf("\n \t Pushing in queue. \n");
            printf("Enter the element you want to enQueue in the queue : ");
            scanf("%d", &element);
            if (noOfItems(&queueA) == maxSpace)
            {
                printf("Queue was full and could not add any item! \n");
            }
            else
            {
                enQueue(&queueA, element);
                printf("\n%d is added.\n", element);
            }
            break;
        case 2:
            printf("deQueue the element from queue. \n");
            value = deQueue(&queueA);

            if (value != INT_MIN)
            {
                printf("\n%d is removed\n", value);
            }
            else
            {
                printf("Queue was empty and could not remove any item! \n");
            }
            break;

        case 3:
            printQueueDetails(&queueA);
            printQueue(&queueA); // calling the display function
            break;
        case 4:
            exit(0);
        default:
            printf("\n \t WRONG CHOICE ENTERED !! \n");
            break;
        }
        printf("\nPress enter to continue... \n");
        getch();
    } while (1);
    return 0;
}