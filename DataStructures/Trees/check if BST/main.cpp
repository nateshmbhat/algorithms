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

bool isBST_maxMethod(Node * root) 
{
    bool flag = 1 ; 
    maxHelper(root , flag) ; 
    return flag ? true : false ; 
}

bool isBST_MinMaxMethod(Node * root , int min = INT_MIN , int max = INT_MAX)
{
    if(!root) return true ; 
    if(min>root->data || max<root->data)  return false ; 
    return isBST_MinMaxMethod(root->l , min , root->data) && isBST_MinMaxMethod(root->r , root->data , max ) ; 
}


bool isBST_inorderTraversalMethod(Node * root , Node * prev = 0 )
{
    // Just keep track of the previous node while doing inorder traversal to check tree
    bool left ; 
    if(!root) return true ; 
    if(!isBST_inorderTraversalMethod(root->l , prev)) return false ; 
    if(prev && prev->data> root->data || (root->l && root->l->data > root->data ) ) return false ; 
    return isBST_inorderTraversalMethod(root->r  , root ); 
}


int main()
{
    vector<int> a = {12 , 63 , 19 } ; 
    Tree tree =  Tree::generateRandBT(3) ; 
    // Tree tree =  Tree::buildCustomTree(a) ; 
    tree.inorder() ; cout<<endl ; 
    tree.prettyPrint() ; cout<<endl ; 
    if(isBST_inorderTraversalMethod(tree.getRoot( ))) 
        cout<<"\nIts a BST ! " ; 
    else  cout << "\nNOT A BST ! " ; 
}