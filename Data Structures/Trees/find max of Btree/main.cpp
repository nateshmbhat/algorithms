#include<bits/stdc++.h>
#include<list>

using namespace std ; 
class Node
{
    public : 

    int data ; 
    Node * l , * r ; 
   
    Node()
    {
        l = r  = 0 ; 
        data = 0; 
    }
};


class Tree
{
    public : 
    Node * root ; 
    int n ;  

    Tree(int data = 0  ){
        root = new Node ; 
        root->l = root->r = 0 ;
        root->data = data ; 
    }

    void inorder(Node *) ;
    void preorder(Node * ) ; 
    void postorder(Node * ) ; 
    void insertBST(int ) ;
} ; 

void Tree::insertBST(int data)
{
    Node * temp=root   ,* parent  = root; 
    Node * newnode = new Node ; 
    newnode->l = newnode->r = 0 ; 
    newnode->data = data ; 
    this->n++ ; ; 

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


int main(void)
{
    Tree T(15) ; 
    T.insertBST(10) ; 
    T.insertBST(20) ; 
    T.insertBST(5) ; 
    T.inorder(T.root) ;     
}