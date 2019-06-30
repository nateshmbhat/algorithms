#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* Linked list Node */
struct Node
{
    int data;
    struct Node* next;
};
struct Node *newNode(int data)
{
    struct Node *new_Node = (struct Node *) malloc(sizeof(struct Node));
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}
struct Node* addTwoLists (struct Node* first, struct Node* second);

void push(struct Node** head_ref, int new_data)
{
    struct Node* new_Node = newNode(new_data);
    new_Node->next = (*head_ref);
    (*head_ref)    = new_Node;
}
void printList(struct Node *Node)
{
    while(Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void freeList(struct Node *Node)
{
	struct Node* temp;
    while(Node != NULL)
    {   
        temp=Node;
        Node = Node->next;
        free(temp);
    } 
}
int main(void)
{
   int t,n,m,i,x;
   cin>>t;
   while(t--)
   {
	   struct Node* res = NULL;
    struct Node* first = NULL;
    struct Node* second = NULL;
	    cin>>n;
	    for(i=0;i<n;i++)
	    {
			cin>>x;
			push(&first, x);
	    }
         cin>>m;
	    for(i=0;i<m;i++)
	    {
			cin>>x;
	    push(&second, x);
	    }
		 res = addTwoLists(first, second);
	    printList(res);
if(first)
freeList(first);
if(second)
freeList(second);
//if(res)
//freeList(res);
   }
   return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*struct Node
{
    int data;
   Node* next;
}; */
//write a function returns the resultant linked list
Node*  addTwoLists(Node* first, Node* second){
  int c = 0 , sum =0  ; 
  Node * resultHead = 0 , *result = 0  ;
  
  while(first && second){
      sum = first->data+ second->data + c ;
      c = sum/10 ;
      
      if(!resultHead){ 
          result=newNode(sum%10) ; 
          resultHead = result ;
      }
      else {
          result->next = newNode(sum%10) ;
          result = result->next ;
      }
      
      first = first->next ;
      second = second->next ; 
  }
  
  while(first){ 
      sum = first->data + c ;
      c = sum/10 ; 
      result->next = newNode(sum%10) ;
      first = first->next ; 
  }
  while(second){
      sum = second->data + c ;
      c = sum/10 ; 
      result->next = newNode(sum%10) ;
      second = second->next ; 
  }
    if(c>0) result->next = newNode(c) ;
    
  return resultHead ; 
}