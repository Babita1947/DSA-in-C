#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct ArrayStack
{
    int top;
    int capacity;
    int *array;
};

struct ArrayStack* createStack(int cap)
{
    struct ArrayStack *stack;
    stack = malloc(sizeof(struct ArrayStack));
    stack->capacity = cap;
    stack->top = -1;
    stack->array = malloc(sizeof(int)*stack->capacity);

    return stack;
}

int isFull(struct ArrayStack* stack)
{
    if(stack->top == stack->capacity-1)
        return (1);
    else
        return (0);
}

int isEmpty(struct ArrayStack* stack){
    if(stack->top == -1)
        return (1);
    else
        return (0);
}

void push(struct ArrayStack* stack,int item){
    if(!isFull(stack)){
        stack->top ++;
        stack->array[stack->top] = item;
    }
}

int pop(struct ArrayStack* stack){
    int deleteItem;
    if(!isEmpty(stack)){
        deleteItem = stack->array[stack->top];
        stack->top--;
        return deleteItem;
    }
    return -1;
}


void display(struct ArrayStack* stack) {
    if (!isEmpty(stack)) {
        printf("Stack elements: ");
        for (int i = 0; i <= stack->top; i++) {
            printf("%d ", stack->array[i]);
        }
        printf("\n");
    } 
    else {
        printf("Stack is empty.\n");
    }
}

int main(){
    int choice,item;
    struct ArrayStack *stack = createStack(5);
    while(1)
    {
        printf("\n 1. Push");
        printf("\n 2. Pop");
        printf("\n 3. Display");
        printf("\n 4. Exit");
        printf("\n Enter your choice : ");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1:
               printf("Enter a number: ");
               scanf("%d",&item);
               push(stack,item);
               break;
            case 2:
               item = pop(stack);
               if(item == -1)
                  printf("Stack is empty");
               else
                  printf("\n Poped value is %d",item);
               break;
            case 3:
                display(stack);
                break;
            case 4:
                free(stack->array); // Free the allocated memory for the array
                free(stack); // Free the allocated memory for the stack
                exit(0);
        }
    }
    return 0;
}