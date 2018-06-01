#include "./trees.h"
#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std; 


void Tree::insertBST(int data)
{
    Node * temp=root   ,* parent  = root; 
    Node * newnode = new Node ; 
    newnode->l = newnode->r = 0 ; 
    newnode->data = data ; 
    this->n++ ; ; 

    if(root==NULL)
    {
        root= newnode ; return ; 
    }

    while(temp)
    {
        parent = temp ; 
        if(data<root->data)
            temp = temp->l ; 
        else temp = temp->r ; 
    }
    
    if(data<parent->data) parent->l = newnode ; 
    else parent->r = newnode ; 
}

void Tree::inorder(Node * root )
{
    if(!root) return  ;     
    inorder(root->l) ; 
    cout<<root->data<<" " ; 
    inorder(root->r) ; 
}

void Tree::postorder(Node * root)
{
    if(!root) return  ;     
    postorder(root->l) ; 
    postorder(root->r) ; 
    cout<<root->data<<" " ; 
}


void Tree::preorder(Node * root)
{
    if(!root) return  ;     
    cout<<root->data<<" " ; 
    preorder(root->l) ; 
    preorder(root->r) ; 
}


int Tree::findMax(Node * root) 
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


Tree Tree::generateRandBST(int no_of_nodes)
{
    srand(time(NULL)) ; 
    Tree T ; 
    for(int i =0 ; i <no_of_nodes ; i++)
    {
        int n = rand()%250 ; 
        if(n<=0 ) 
            n = rand()%5 + 1 ; 
        T.insertBST(n) ; 
    }
    return T ; 
}

ostream& operator<<(ostream& out, Tree& T)
{
    T.inorder(T.root) ; 
    return out ; 
}