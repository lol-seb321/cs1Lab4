/* COP 3502C - Lab 4 - Spring 23

This program is written by: Sebastian Ferreira 

This code implements some basic operation of singly linked list like inserting in 
the beginning and end, delete operation, and display operation
*/

// pre processor directives
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
// function prototype
node* reverse(node* head);
void insertToPlace(node* head, int val, int place);
void display(node* t);
node*  insert_front(node *root, int item);

node* reverse(node* head)
{
  // this indicates we have no nodes or only one node and then we should just exit the function by returning head
  // no need to reverse if head is null or only one node in list
  if(head == NULL || head->next == NULL)
  {
    return head;
  }

  // keep track of the nodes first with one that points to the main list and another
  // to the reversed list also the reversed list will have its next pointing to null
  node* main_list = head->next;
  node* reversed_list = head;
  
  reversed_list->next = NULL;

  // traverse through list 
  while(main_list != NULL)
    {
      // keep track of the current node in the main list
      node* temp = main_list; // this is like right in my slides
      
      // move the main list pointer itself to the next one
      main_list = main_list->next;

      // reverse the current node and point it to the reversed list
      // the current node being held by temp
      temp->next = reversed_list;

      // move the reversed list pointer to the current node held by the temp node
      // update head of RV
      reversed_list = temp;
    }
  
  return reversed_list;
}

/*
This function takes a given value (val) from the user and a specific index (place) in which the new node must be inserted into the existing singly linked list. The linked list is represented as the pointer to its head node which is also passed into the funcitons parameter.
*/
void insertToPlace(node* head, int val, int place)
{
/*
If the head of the linked list is NULL OR the specified place to be inserted into is less than or equal to 1, the function prints that its not valid and returns therefore exiting the function.
*/
  if(head == NULL || place <= 1)
  {
    printf("List is empty or place is not valid ");
    return; // print return statement
  }

/* 
Now we know a node exists and that the place we want to insert is greater than 1 we have to make a new node.
*/
  node* temp = malloc(sizeof(node));
  temp->data = val;
  temp->next = NULL;

/*
This while loop travereses through the list until it reaches the node immediately before the specified place we also check to make sure we haven't reached the NULL pointer to ensure we dont go off the list. Both of these    must be true before we exit the while loop.
*/
  int cnt = 1;
  while(head->next != NULL && cnt < place - 1) // place-1 ensures we stop before the place we want to insert into
  {
    head = head->next; // this travereses the list
    cnt++; // update our counter
  }
/*
The next pointer of the temp node is set to the current node at that specified place. The next pointer of the node before the specified place is set to the new node so we dont lose the new node and inserting it into the list.
*/
  temp->next = head->next;
  head->next = temp;
}


// this function takes an item and insert it in the linked list pointed by root.
node*  insert_front(node *root, int item)
{
  node *temp;
  
  // create a new node and fill-up the node
  temp = (node *) malloc(sizeof(node));
  
  // fill up the new node with the data we pass in
  temp->data=item;

  // set next to null so we can indicate next, otherwirse it will point to garbage
  temp->next=NULL;
  
  if(root==NULL) //if there is no node in the linked list
          root=temp;
      else //there is an existing linked list, so put existing root after temp
      {
          temp->next = root; //put the existing root after temp
          root = temp; //make the temp as the root!
      }
    return root;
}

// take the head of a linked list and print the list
void display(node* t)
{
  printf("\nPrinting your linked list.......");
  
  // traverse linked list until we find the NULL then STOP this indicates the end of the list
  while(t!=NULL)
  {
    printf("%d ",t->data); // printing data 
    t=t->next; // setting t to next so we can print the data in the next node
  }
}

// driver function
int main()
{
  node *root=NULL; //very important line. Otherwise all function will fail
  node *t;
  int ch,ele,v, place;
  while(1)
  {
    printf("\n1. insert at front, 2. reverse list 3. Insert to place 0. exit:   ");
    scanf("%d",&ch);
  if(ch==0)
  {
    printf("\nGOOD BYE>>>>\n");
    break;
  }
    if(ch==1)
  {
    printf("\nEnter data(an integer): ");
    scanf("%d",&ele);
    root = insert_front(root, ele);
    display(root);
  }
    if(ch==2)
  {
    root = reverse(root);
    printf("List reversed\n");
    display(root);
  }
    if(ch==3)
    {
      printf("\nEnter data (an integer) and place (>1) separated by space: ");
      scanf("%d %d", &ele, &place);
      insertToPlace(root, ele, place);
      display(root);
    }
  }
    return 0;
}
