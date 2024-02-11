#include<stdio.h>
#include<stdlib.h>

struct ArrayStack
{
    int top;
    int capacity;
    int *array;
};

struct ArrayStack* createArray(int cap){
    struct ArrayStack *stack;
    stack = malloc(sizeof(struct ArrayStack));
    stack->capacity = cap;
    stack->top = -1;
    stack->array = malloc(sizeof(int)*stack->capacity);
    return stack;
}

int isFull(struct ArrayStack *stack){
    if(stack->top == stack->capacity - 1)
       return 1;
    else
       return 0;
}

int isEmpty(struct ArrayStack *stack){
    if(stack->top == -1)
       return 1;
    else 
       return 0;
}

void push(struct ArrayStack *stack,int item){
    if(!isFull(stack)){
        stack->top ++;
        stack->array[stack->top] = item;
    }
}

int pop(struct ArrayStack *stack){
    if(!isEmpty(stack)){
        int delItem = stack->array[stack->top];
        stack->top--;
        return delItem;
    }
    return -1;
}

void display(struct ArrayStack *stack){
    if(!isEmpty(stack)){
        printf("Stack Elements are : ");
        for(int i=0;i<=stack->top;i++){
            printf("%d ",stack->array[i]);
        }
        printf("\n");
    }
    else{
        printf("Stack is empty");
    }
}

int main(){
    struct ArrayStack *stack = createArray(10);
    int choice ,item ;
    while(1){
        printf("\n 1.Push");
        printf("\n 2.Pop");
        printf("\n 3.Display");
        printf("\n 4.Exit");
        printf("\n Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
              printf("Enter a number: ");
              scanf("%d",&item);
              push(stack,item);
              break;
            case 2:
              item = pop(stack);
              if(!isEmpty(stack))
                printf("\n Poped element is %d",item);
              else
                printf("\n Stack is Empty\n");
              break;
            case 3:
               display(stack);
               break;
            case 4:
               free(stack->array);
               free(stack);
               exit(0);
        }
    }
    return 0;
}
