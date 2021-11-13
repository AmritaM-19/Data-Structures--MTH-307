//Program to generate a circularly linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head;
void create(int n);
void display();
int main()
{
    int n;
    printf("Enter the number (at least 7) node:\n");
    scanf("%d", &n);
    create(n);
    printf("Here are the contents of the linked list\n");
    display();
    return 0;
}
void create(int n)
{
struct node *newnode, *temp;
int data, i;
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

//Creating the rest n-1 nodes
temp= head; //temporary variable to store address of previous nodes
for(i=2; i<=n; i++)
{
newnode = (struct node *)malloc(sizeof(struct node));
//checking availability of memory for new node
if(newnode == NULL)
{
printf("Unable to allocate memory.");
break;
}
printf("Enter the data of node %d: ", i);
scanf("%d", &data);
newnode->data = data; // Linking data field of newNode
newnode->next = NULL; // Make sure new node points to NULL 
temp->next = newnode; // Link previous node with newNode
temp = temp->next;    // Make current node as previous node
}//end of for loop
temp->next= head; //linking the last node to the head or first node
printf("Circularly Linked list generated\n");
}
//to print the list
void display()
{
struct node *current;
int n = 1;
if(head == NULL)
{
printf("List is empty.\n");
}
else
{
current = head;
printf("DATA IN THE LIST:\n");
do 
{
printf("Data %d = %d\n", n, current->data);
current = current->next;
n++;
}while(current != head);
}
}