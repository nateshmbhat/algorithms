#include<bits/stdc++.h>
#include"../utils.h"
using namespace std; 


bool hasPathSum(Node * root , int sum , int currentSum =0 ) 
{
    if(!root) return false ; 

    currentSum+=root->data ; 
    if(!root->l && !root->r){ return (sum==currentSum) ? true : false ; }
    return hasPathSum(root->l , sum , currentSum) || hasPathSum(root->r , sum , currentSum ) ; 
}

int main(void)
{
    vector<int> a = { 1 , 2,3 , 4, 0 ,  5, 6 , 8 , 9 , 10 }  ;  

   Tree tree = Tree().buildCustomTree(a) ; 
   
   tree.prettyPrint() ; 
   int sum = 19 ; 

   cout<< "Path with sum  = " << sum << " exists : " << (hasPathSum(tree.getRoot()  , sum )? "True" : "False") <<endl;
}