#include<stdio.h>
#include<stdlib.h>

struct node
{
   char data;
   struct node* next;
};

struct node* START = NULL;

struct node* createNode()
{
    struct node* n;
    n = (struct node*)malloc(sizeof(struct node));
    return n;
}

void push(char item)
{
    struct node *n;
    n = createNode();
    n->data = item;
    n->next = START;
    START = n;
}

char peek()
{
    if(START == NULL)
       printf("\nEmpty Stack");
    else
       return START->data;

}

void pop()
{
    struct node *temp;
    if(START != NULL){
        temp = START;
        START = temp->next;
        free (temp);
    }
}

void display()
{
    struct node *temp;
    printf("Stack elements : ");
    if(START == NULL)
      printf("Empty stack");
    else{
      temp = START;
      while(temp != NULL){
        printf("%c ",temp->data);
        temp = temp->next;
      }
    }
}

int main()
{
    char ch;
    int choice;
    while(1)
    {
        printf("\n 1. PUSH");
        printf("\n 2. POP");
        printf("\n 3. PEEK");
        printf("\n 4. Display");
        printf("\n 5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
               printf("Enter a character: ");
               scanf(" %c",&ch);
               push(ch);
               break;
            case 2:
               pop();
               break;
            case 3:
               ch = peek();
               printf("Peek element = %c",ch);
               break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
        }
    }
    return 0;
}
