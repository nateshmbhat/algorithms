#include "utils.h"
#include<iostream>
#include<ctime>
#include<bits/stdc++.h>
#include<cstdlib>
using namespace std; 


void printSpace(int space){for(int i =0 ; i < space ; i++)cout<<" " ;}

void Tree::insertBST(int data)
{
    Node * newnode  = new Node; 
    newnode->l = newnode->r = 0 ; 
    newnode->data = data ; 
    Node * temp = this->root  , * parent = root ; 
    this->n++ ; 

    while(temp){
       parent = temp ; 
       if(data<temp->data) temp = temp->l ;  
       else temp = temp->r ; 
    }
    if(parent->data<data) parent->r = newnode; else parent->l = newnode; 
}

bool isQueueNull(queue<Node*> myqueue){
   //* Checks if all the elments in queue are null and returns true if so  */ 
   while(!myqueue.empty())
   { 
        if(myqueue.front())return false ; 
        myqueue.pop() ; 
   }
    return true ; 
}

Tree::Tree(int data ){

        srand(time(NULL)) ; 
        root = new Node ; 
        root->l = root->r = 0 ;
        root->data = data?data : rand()%50 ; 
        n = 1 ; 
    }



void Tree::prettyPrint(int centerPosition){
    queue<Node*> myqueue  ; 
    myqueue.push(root) ; 
    while(!isQueueNull(myqueue))
    {
        printSpace(centerPosition) ; 
        int rowsize = myqueue.size() ; 
        for(int i =0 ; i < rowsize ;i++)
        {
            if(myqueue.front()) cout<< myqueue.front()->data ; 
            else cout<<"_" ; 
            printSpace(2); 
            myqueue.front()? myqueue.push(myqueue.front()->l) : myqueue.push(0) ;
            myqueue.front()? myqueue.push(myqueue.front()->r) : myqueue.push(0) ;
            myqueue.pop(); 
        }
        centerPosition-=2 ;
        cout<<endl; 
    }
}

Node * Tree::getRoot(){return root ; }



void Tree::inorder(Node * rootvar )
{
    if(!rootvar) return  ;     
    if(rootvar==(Node *)-1)
    {

        inorder(this->root) ;
        return ; 
    }
    inorder(rootvar->l) ; 
    cout<<rootvar->data<<" " ; 
    inorder(rootvar->r) ; 
}

void Tree::postorder(Node * root )
{
    if(!root) return  ;     
    if(root==(Node *)-1)
    {
        this->postorder(this->root) ; 
        return ; 
    }
    postorder(root->l) ; 
    postorder(root->r) ; 
    cout<<root->data<<" " ; 
}


void Tree::preorder(Node * root)
{
    if(!root) return  ;     
    if(root==(Node *)-1)
    {

        this->preorder(this->root) ;
        return ;
    }
    cout<<root->data<<" " ; 
    preorder(root->l) ; 
    preorder(root->r) ; 
}


int Tree::findMax(Node * root )
{
    if(!root) return 0 ;
    int l = findMax(root->l) ;
    int r = findMax(root->r) ;
    return max(root->data , max(l ,r)) ;
}


bool Tree::isBST(Node * root)
{
    if(!root) return true;
    int l = findMax(root->l) ;
    int r = findMax(root->r) ;
    
    if(root->data<l || root->data>r)
        return false ; 
    return true ; 
}


Tree Tree::generateRandBST(int no_of_nodes , int randmin , int randmax )
{
    for(int i =0; i < no_of_nodes  ; i++)
    {
        this->insertBST((rand()%(randmax-randmin)) + randmin) ; 
    }
    return *this ; 
}

Tree Tree::generateRandBT(int no_of_nodes)
{
    if(no_of_nodes) ; 
}


ostream& operator<<(ostream& out, Tree& T)
{ 
    deque<Node *> Q ; 
    Q.emplace_back(T.root) ; 
    
}


ostream& operator<<(ostream& out , Node * root)
{
    if(!root) return out ;

    cout<<root->data<<"  ---  " ; 
    cout<<root->l ;
    cout<<root->r <<endl;  
}