#include<bits/stdc++.h>
#include"../utils.h"
using namespace std; 

void inorder(Node * root)
{
    if(!root) return ; 
    stack<Node * > stk ;  Node * cur  = root ; 
    stk.push(root) ; cur = root->l ; 

    while(!stk.empty() || cur )
    {
        while(cur) {
            stk.push(cur)  ; 
            cur = cur->l ; 
        }
        cout<<stk.top()->data <<" " ; 
        cur = stk.top()->r ; stk.pop() ; 
    }
}



void preorder(Node * root)
{
    if(!root) return ; 
    stack<Node * > stk ; 
    stk.push(root) ; 
    Node *top ; bool  flag  = 1  ; 

    while(!stk.empty())
    {
        top = stk.top() ; stk.pop() ;
        cout<<top->data<<" " ;  
        if(top->r) stk.push(top->r) ; 
        if(top->l) stk.push(top->l) ; 
    }
}



void postorder(Node * root)
{
    if(!root) return ; 
    stack<Node * > stk ; if(root->r) stk.push(root->r) ; 

    while(!stk.empty() )
    {
        while(root){if(root->r) stk.push(root->r) ; stk.push(root) ; root = root->l ;  }

        root = stk.top() ; stk.pop() ; 

        if(stk.empty()) return ; 

        if(root->r && root->r==stk.top()){
            stk.pop() ; stk.push(root) ; 
            root = root->r ; 
        } 
        else
        {
            cout<< root->data <<" " ; 
            root = 0 ;  
        }
    }
}


int main(void)
{

    Tree mytree(50) ;
    // vector<int> bsftree = {32 ,21 , 42, 18 , 0 , 0 , 88, 14 , 0 , 78 , 92 , 0 , 0 ,66 , 0 , 0,0,0,73} ;
    // vector<int> bsftree = {50 , 42 , 71 , 27,48,66,99,6,35,42,48,65 , 0,82,0,5, 7,0,0,0,0,0,0,0,0,90,0,1,0,0,13,0,96,0,2,0,25} ; 
    
    vector<int> bsftree = {6 , 5, 7 , 1 , 0 , 0 , 13 , 0 , 2 , 0 , 25 , 0, 0, 21962} ; 

    Tree tree = mytree.buildCustomTree(bsftree) ; 
    // Tree tree = mytree.generateRandBST(20) ; 

    tree.prettyPrint() ;cout<<endl;  
    cout<<"inorder : " ; tree.inorder() ; cout<<endl; 
    cout<<"inorder : " ; inorder(tree.getRoot()) ; 

    cout<<endl<<"preorder : " ; tree.preorder() ; cout<<endl; 
    cout<<"preorder : " ; preorder(tree.getRoot()); cout<<endl; 

    cout<<endl<<"postorder : " ; tree.postorder() ; cout<<endl; 
    cout<<"postorder : " ; postorder(tree.getRoot()) ; cout<<endl; 
}