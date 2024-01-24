#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
    struct node *prev;
    int item;
    struct node *next;
};
struct node *start = NULL;

struct node* createNode()
{
    struct node *n;
    n = (struct node*)malloc(sizeof(struct node));
    return n;
}

void insertAtFirstNode(int data)
{
    struct node *n;
    n = createNode();
    n->prev = NULL;
    n->item = data;
    n->next = start;
    if(start != NULL)
      start->prev = n;
    start = n;
}

void insertAtLastNode(int data)
{
    struct node *n;
    struct node *t;
    n = createNode();
    n->item = data;
    n->next = NULL;

    if(start == NULL)
    {
        n->prev = start;
        start = n;
    }
    else
    {
        t = start;
        while(t->next != NULL)
          t = t->next;
        n->prev = t;
        t->next = n;
    }
}
void deleteFirstNode()
{
    struct node *t;

    if(start == NULL)
      printf("List is empty , deletion not possible");
    else
    {
       t = start;
       start = t->next;
       start->prev = NULL;
       free (t);
    }
}

void deleteLastNode()
{
    struct node *t;
    if(start == NULL)
      printf("List is underflow");
    else if(start->next == NULL)
    {
        free(start);
        start = NULL;
    }
    else 
    {
        t = start;
        while(t->next != NULL)
          t = t->next;
        t->prev->next = NULL;
        free(t);
    }
}

bool search(int data)
{
    struct node *temp;
    if(start == NULL)
      printf("Underflow");
    temp = start;
    while(temp)
    {
        if(temp->item == data)
           return true;
        temp = temp->next;
    }
    return false;
}
void displayList()
{
    struct node *temp;
    if(start == NULL)
      printf("List is Empty");
    temp = start;
    while(temp)
    {
        printf("%d ",temp->item);
        temp = temp->next;
    }
}
int menu()
{
    int ch;
    printf("\n1. Insert at first ");
    printf("\n2. Insert at Last");
    printf("\n3. Delete first node");
    printf("\n4. Delete last node");
    printf("\n5. search element");
    printf("\n6. displayList");
    printf("\n7. Exit");
    printf("\n\n Enter your choice");
    scanf("%d",&ch);
    return ch;
}
int main()
{
    int n;
    while(1)
    {
        switch(menu())
        {
            case 1:
              
              printf("Enter a number :");
              scanf("%d",&n);
              insertAtFirstNode(n);
              break;
            case 2:
              
              printf("Enter a number :");
              scanf("%d",&n);
              insertAtLastNode(n);
              break;
            case 3:
              deleteFirstNode();
              break;
            case 4:
              deleteLastNode();
              break;
            case 5:
              
              printf("Enter a number :");
              scanf("%d",&n);
              int ans;
              ans = search(n);
              if(ans == 0)
                printf("Sorry data not present");
              else 
                printf("Data present");
              break;
            case 6:
                displayList();
                break;
            default:
                exit(0);
                
        }
    }
    return 0;
}

