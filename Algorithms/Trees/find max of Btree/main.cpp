#include<bits/stdc++.h>
#include "../utils.h"

using namespace std ; 

int findMax(Node * root)
{
    if(!root) return INT_MIN ; 
    return max(max(root->data , findMax(root->l)) , findMax(root->r)) ; 
}

int main(void)
{
    Tree tree(50) ; 
    tree = tree.generateRandBT(10) ;
    cout<<"inorder : "  ;  tree.inorder()  ; cout<<endl; 
    cout<<"preorder : " ;  tree.preorder() ; cout<<endl; 
    tree.prettyPrint() ; 
    cout<<"\nMax is = " <<findMax(tree.getRoot()) ; 
}