#include<stdio.h>
#include<stdlib.h>
 struct node
{
int data;
struct node *left;
struct node *right;
} node;

 struct node *create()
{
 struct node *p;
int x;
printf("Enter data(-1 for no data):");
scanf("%d",&x);
if(x==-1)
return NULL;
p=(struct node*)malloc(sizeof(struct node));
p->data=x;
printf("Enter left child of %d:\n",x);
p->left=create();
 
printf("Enter right child of %d:\n",x);
p->right=create();
return p;
}
int main()
{
struct node *root;
root = 0;
root=create();
return 0;
}