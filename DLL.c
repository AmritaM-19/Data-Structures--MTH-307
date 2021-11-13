//Program to create and print a doubly linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data; //data part
    struct node *prev, *next; //two way pointers or address part
}*head,*last;
//functions used in program
void createlist(int n);
void displaylist();
int main()
{
    int n;
    head= NULL;
    last= NULL;
    printf("Enter the number (at least 7) of nodes:\n");
    scanf("%d", &n);
    createlist(n);
    displaylist();
    return 0;
}
//creating a doubly linked list
void createlist(int n)
{
    int i, data;
    struct node *newnode;
    head= (struct node *)malloc(sizeof(struct node));
//checking for memory allocation
if(head==NULL)
{
    printf("Failed to allocate memory");
    exit(0);
}
printf("Enter data of node 1:\n");
scanf("%d", &data);
head->data = data; // Linking data field with data
head->next = NULL; // Linking address field to NULL
head->prev= NULL;
last=head;
//Creating the other n-1 nodes
for(i=2; i<=n; i++)
{
newnode = (struct node *)malloc(sizeof(struct node));
if(newnode != NULL)
{
printf("Enter data of %d node: ", i);
scanf("%d", &data);
newnode->data = data;
newnode->prev = last; // Link new node with the previous node
newnode->next = NULL;
last->next = newnode; // Link previous node with the new node
last = newnode;          // Make new node as last/previous node
}
else 
{
    printf("Failed to allocate memory!\n");
    break;
}
}
printf("Doubly Linked List created\n");
}
//printing the list
void displaylist()
{
struct node *temp;
// Return if list is empty 
if(head == NULL)
{
printf("List is empty.");
return;
}
temp = head;
while(temp != NULL)
{
printf("Data = %d\n", temp->data); // Print data of current node
temp = temp->next;                 // Move to next node
}    
}
