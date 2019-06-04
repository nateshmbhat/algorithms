#include<bits/stdc++.h>
#include"../utils.h"
using namespace std; 


Node * lowestCommonAncestor(Node * root , int data1 , int data2)
{
    if(!root) return 0 ; 
    if(root->data ==data1 || root->data==data2) return root ; 

    Node * left = lowestCommonAncestor(root->l , data1 , data2) ; 
    Node * right = lowestCommonAncestor(root->r , data1 , data2) ; 

    if(left && right) return root ;
    return left ? left: right ; 
}


int main(void)
{
   vector<int> a = { 1 , 2,3 , 4, 0 ,  5, 6 , 8 , 9 , 10 }  ;  
   Tree tree = Tree().buildCustomTree(a) ; 
   
   tree.prettyPrint() ; 
   Node * ans = lowestCommonAncestor(tree.getRoot() , 4 , 9) ; 
   if(ans) cout << ans->data <<endl;
}
