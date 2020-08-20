#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

/*
    --------------       *======*======*
    Node Structure  -->  | data | next |
    --------------       *======*======*
*/

struct Node
{
    int data;
    struct Node *next;
}*head;

// Insert Node at First
void insertAtFirst(int d)
{
    struct Node *t = (struct Node* )malloc(sizeof(struct Node));
    t->next = NULL;
    t->data = d;
    if(head==NULL)
    {
        head = t;
    }
    else
    {
        t->next = head;
        head = t;
    }
}

// Insert Node at Last
void insertAtLast(int d)
{
    struct Node *t = (struct Node* )malloc(sizeof(struct Node));
    t->next = NULL;
    t->data = d;
    if(head==NULL)
    {
        head = t;
    }
    else
    {
        struct Node * temp = head;
        while(temp->next!=NULL)
            temp = temp->next;
        temp->next = t;
    }
}

// Delete First Linked List Node
void deleteFirst()
{
    if(head!=NULL)
    {
        struct Node * temp = head;
        head = head->next;
        free(temp);
    }  
}

// Delete Last Linked List Node
void deleteLast()
{
    if(head->next!=NULL)
    {
        struct Node * temp = head;
        while(temp->next->next!=NULL)
            temp = temp->next;
        struct Node *t = (struct Node* )malloc(sizeof(struct Node));
        t = temp->next;
        free(t);
        temp->next = NULL;
    }  
}

// Display Linked List Nodes Iteratively
void displayList()
{
    struct Node* temp = head;
    if(head!=NULL)
    {
        while(temp->next!=NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("%d", temp->data);
        printf("\n");
    }
    else
    {
        printf("Nothing to display. Linked List is Empty.\n");
    }
}

// Display Linked List Nodes Recursively
void displayListRecursive(struct Node *node)
{
    if(node==NULL)
        return;
    printf("%d ", node->data);
    displayListRecursive(node->next);
}

// Display Linked List Nodes in Reverse order Recursively
void displayListReverse(struct Node *node)
{
    if(node==NULL)
        return;
    displayListReverse(node->next);
    printf("%d ", node->data);
}


int main()
{
    insertAtFirst(1);
    insertAtFirst(2);
    insertAtFirst(3);
    insertAtLast(0);
    displayList();
    deleteFirst();
    displayList();
    deleteLast();
    displayList();
    displayListReverse(head);
    printf("\n");
    displayListRecursive(head);
    return 0;
}