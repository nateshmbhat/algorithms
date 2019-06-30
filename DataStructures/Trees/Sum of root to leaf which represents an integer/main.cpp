#include<bits/stdc++.h>
#include"../utils.h"
using namespace std; 


/* 

Input : 
                1
               / \
              2  3


Output :   sum = 12 + 13 = 25

 */

int sumFromRootToLeaf(Node * root , int cur ) 
{
    if(!root) return 0 ; 
    cur = cur * 10 + root->data ; 
    if(!root->l && !root->r) return  cur; 
    return sumFromRootToLeaf(root->l , cur)+ sumFromRootToLeaf(root->r , cur) ; 
}


int main(void)
{
   vector<int> a = { 1 , 2,3 , 0 , 4 , 7 , 8 } ; 
   Tree tree = Tree().buildCustomTree(a) ; 
   
   tree.prettyPrint() ; 
   cout<< " sum = " << sumFromRootToLeaf(tree.getRoot() , 0) <<endl ;
}