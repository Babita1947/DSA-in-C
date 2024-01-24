#include<stdio.h>

#include<stdlib.h>
#include<stdbool.h>
struct node
{
    int info;
    struct node *link;
};

struct node *START = NULL;
struct node* createNode()
{
    struct node *n;
    n = (struct node*)malloc(sizeof(struct node));
    return n;
}

void insertAtLastNode(int data)
{
    struct node *temp;
    struct node *t;

    temp = createNode();
    temp->info = data;
    temp->link = NULL;

    if(START == NULL)
       START = temp;
    else 
    {
       t = START;
       while(t->link != NULL)
          t = t->link;
       t->link = temp;

    }
}
void insertAtFirstNode(int data)
{
    struct node *n;
    n = createNode();
    n->info = data;
    
    if(START == NULL)
    {
        n->link = NULL;
        START = n;
    }
    else
    {
       n->link = START;
       START = n; 
    }
    
}

void deleteFirstNode()
{
    struct node *temp;
    if(START == NULL)
        printf("Deletion not possible list is Empty");
    else{
        temp = START;
        START = START->link;
        free (temp);
    }
}
void deleteLastNode()
{
    struct node *t;
    if(START == NULL)
      printf("Deletion not possible because list is Empty");
    else
    {
        t = START;
        if(t->link == NULL)
        {
            free(t);
            START = NULL;
        }
        else
        {
            while(t->link->link != NULL)
               t = t->link;

            free(t->link);
            t->link = NULL;
        }
    }

}
bool search(int data)
{
    struct node *temp;
    if(START == NULL)
      printf("List is Empty");
    else
    {
       temp = START;
       while(temp)
       {
         if(temp->info == data)
            return true;
         else
           temp = temp->link;
       }
    }
    return false;
}
void displayList()
{
    struct node *temp;
    if(START == NULL)
      printf("Empty List");
    else{
        temp = START;
        while(temp != NULL){
        printf("%d ",temp->info);
        temp = temp->link;
        }
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
