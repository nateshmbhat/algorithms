#include "utils.h"
#include<iostream>
#include<ctime>
#include<bits/stdc++.h>
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


Tree Tree::generateRandBST(int no_of_nodes)
{
    srand(time(NULL)) ; 
    for(int i =0 ; i <no_of_nodes ; i++)
    {
        int nvar = rand()%250 ; 
        if(nvar<=0 ) 
            nvar = rand()%5 + 1 ; 
        this->insertBST(nvar) ; 
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