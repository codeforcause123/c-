#include <stdio.h>
#include <stdlib.h>
struct node //Node Structure
{
    int data;
    struct node *next;
} *head = NULL;
//Function to insert at beginning of linked list
void insertatHead(struct node **head, int x){ 
    struct node *n = (struct node *)malloc(sizeof(struct node));// Memory allocation
    n->data = x;
    n->next = *head;
    *head = n;
}
//Function to display linked list
void display(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("-->%d", temp->data);
        temp = temp->next;
    }
}
void printMiddle(struct node *head)
{
    int count = 0, i = 0;
    struct node *temp = head;
    while (temp != NULL){ // Counting the number of nodes
        count++;
        temp = temp->next;
    }
    count = (count) / 2; // Dividing by 2
    temp = head;
    while (i < count) //Traversing till middle
    {
        temp = temp->next;
        i++;
    }
    printf("\nThe middle element is [%d]", temp->data);
}
int main()
{
    int n, i;
    printf("Enter length of linked list: ");
    scanf("%d", &n);// Length of linked list
    printf("Enter values: ");
    for (i = 0; i < n; i++) {// Scanning elements and inserting in linked list
        int val;
        scanf("%d", &val);
        insertatHead(&head, val);
    }
    printf("Linked list:");
    display(head); //Displaying the list
    printMiddle(head); // Printing the middle elements
    return 0;
}