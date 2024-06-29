#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct node
{
    int data;
    struct node *next;
} *head1 = NULL, *head2 = NULL;

void insertatTail(struct node **head, int x)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = x;
    n->next = NULL;
    if (*head == NULL)
    {
        *head = n;
        return;
    }
    struct node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}
void display(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}
int genNum(struct node *head)
{
    int len = 0, num = 0;
    struct node *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    temp = head;
    while (len > 0)
    {
        num += (int)(pow(10, len - 1) + 0.1) * (temp->data);
        len--;
        temp = temp->next;
    }
    return num;
}
int main()
{
    int n1, n2, i, j, num;
    printf("Enter length of First Linked list: ");
    scanf("%d", &n1);
    for (i = 0; i < n1; i++)
    {
        int val;
        scanf("%d", &val);
        insertatTail(&head1, val);
    }
    printf("Enter length of Second Linked list: ");
    scanf("%d", &n2);
    for (j = 0; j < n2; j++)
    {
        int val;
        scanf("%d", &val);
        insertatTail(&head2, val);
    }
    printf("First Linked List: ");
    display(head1);
    printf("\nSecond Linked List: ");
    display(head2);
    num = genNum(head1) + genNum(head2);
    printf("\nSum = %d", num);
    return 0;
}