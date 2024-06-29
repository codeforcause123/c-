#include <stdio.h>
#include <stdlib.h>
struct node{ //Node Structure
    int data;
    struct node *next;
}*head=NULL;
//Function to insert at end of linked list
void insertatTail(struct node **head,int x){
    struct node *n=(struct node *)malloc(sizeof(struct node));//Memory allocation of node 
    n->data=x;
    n->next=NULL;
    if(*head==NULL){ //if node is first node
        *head=n;
        return;
    }
    struct node *temp=*head;
    while(temp->next!=NULL){  
        temp=temp->next;
    }
    temp->next=n; // Traversing and inserting at the end
}
//Function to display linked list
void display(struct node *head){
    struct node *temp=head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL");
}
//Function to remove duplicates
struct node *removeDuplicates(struct node *head){
    struct node *temp=head;
    struct node *next_to_next; 
    while(temp->next!=NULL){
        if(temp->data==temp->next->data){ //comparing current and it's next node's data
            next_to_next=temp->next->next;
            free(temp->next); // deleting the duplicate node
            temp->next=next_to_next; 
        }
        else{
            temp=temp->next; // traversing to next
        }
    }
    return head;
}
int main(){
    int n,i;
    printf("Enter number of elements: ");
    scanf("%d",&n); //Input number of elements
    printf("Enter the elements: ");
    for(i=0;i<n;i++){// Scanning elements and inserting in linked list
        int val;
        scanf("%d",&val);
        insertatTail(&head,val);
    }
    struct node *newhead=removeDuplicates(head);
    printf("New Linked List: "); //Displaying the linked list
    display(newhead);
    return 0;
}