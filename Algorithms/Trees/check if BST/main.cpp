#include<bits/stdc++.h>
#include"../utils.h"

using namespace std; 
using namespace std ; 

int maxHelper(Node * root , bool & bstflag )
{
    if(!bstflag) return 0 ; 
    int maxleft = root->l ? maxHelper(root->l , bstflag) : INT_MIN ;
    int maxright = root->r ? maxHelper(root->r , bstflag): root->data ;  
    if(!(root->data > maxleft && root->data<=maxright))
        {bstflag = 0 ; }
    return max(max(root->data , maxleft) , maxright) ; 
}

bool isBST(Node * root) 
{
    bool flag = 1 ; 
    maxHelper(root , flag) ; 
    return flag ? true : false ; 
}


int main()
{
    Tree T ; 
    Tree tree =  T.generateRandBST(10) ; 
    tree.inorder() ; cout<<endl; 
    tree.prettyPrint() ; cout<<endl; 
    if(isBST(tree.getRoot())) 
        cout<<"\nIts a BST ! " ; 
    else  cout << "\nNOT A BST ! " ; 
}