#include<bits/stdc++.h>
#include"../utils.h"
using namespace std; 


int findHeight(Node * root , bool & flag)
{
    if(!root) return -1; 
    int left = findHeight(root->l , flag); 
    int right = findHeight(root->r , flag) ; 

    if(abs(left-right)>1) flag = 0 ; 
 
    return max(left , right ) + 1 ; 
}


int main(void)
{
    vector<int> a = { 10 , 0  , 30 , 0 , 30}  ; 
    Tree mytree = Tree().buildCustomTree(a) ; 
    mytree.prettyPrint() ;
    bool flag  = 1 ;
    findHeight(mytree.getRoot() , flag) ; 
    cout<< (flag?"True" : "false") ; 
}