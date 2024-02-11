#include<stdio.h>
#include<stdlib.h>
#include<conio.h> // For clrscr() and getch()

struct ArrayQueue
{
    int capacity;
    int front;
    int rear;
    int *array;
};

struct ArrayQueue* createQueue(int cap)
{
    struct ArrayQueue *queue;
    queue = malloc(sizeof(struct ArrayQueue));
    queue->capacity = cap;
    queue->front = -1;
    queue->rear = -1;
    queue->array = malloc(cap * sizeof(int)); // Allocate memory for the array
    return queue;
}

int isFull(struct ArrayQueue* queue)
{
    if ((queue->front == 0 && queue->rear == queue->capacity - 1) ||
        (queue->rear == (queue->front - 1) % queue->capacity))
        return 1;
    else
        return 0;
}

int isEmpty(struct ArrayQueue* queue)
{
    if(queue->front == -1 && queue->rear == -1)
       return 1;
    else
       return 0;
}

void push(struct ArrayQueue *queue, int data)
{
    if(isFull(queue)) {
        printf("Queue is FULL");
        return;
    }

    if(queue->front == -1)
        queue->front = 0;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = data;
}

int getFront(struct ArrayQueue *queue)
{
    if(isEmpty(queue)) {
        printf("Empty Queue");
        return -1; // Return a special value indicating error
    }
    return queue->array[queue->front];
}

void pop(struct ArrayQueue *queue)
{
    if(isEmpty(queue)) {
        printf("Empty Queue");
        return;
    }

    if(queue->front == queue->rear)  // only one element
       queue->front = queue->rear = -1;
    else
       queue->front = (queue->front + 1) % queue->capacity;
}

void display(struct ArrayQueue *queue)
{
    if(isEmpty(queue)) {
       printf("\nQueue is Empty");
       return;
    }
    
    printf("Queue Elements : ");
    int i = queue->front;
    do {
        printf("%d ", queue->array[i]);
        i = (i + 1) % queue->capacity;
    } while (i != (queue->rear + 1) % queue->capacity);
}

int main()
{
    
    int choice;
    int num;
    struct ArrayQueue *queue = createQueue(5);
    while(1)
    {
        printf("\n1. ENQUEUE");
        printf("\n2. DEQUEUE");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1:
               printf("Enter a number: ");
               scanf("%d",&num);
               push(queue,num);
               break;
            case 2:
               pop(queue);
               break;
            case 3:
               display(queue);
               break;
            case 4:
               free(queue->array);
               free(queue);
               return 0; // Return 0 to indicate successful execution
        }
    }
    getch(); // Wait for a key press before exiting
    return 0; // Return 0 to indicate successful execution
}
