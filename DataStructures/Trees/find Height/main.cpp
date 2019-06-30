#include<bits/stdc++.h>
#include"../utils.h"
using namespace std; 


int findHeight(Node * root)
{
    if(!root)return 0 ;
    return max(findHeight(root->l) , findHeight(root->r))+ 1 ; 
}


int main(void)
{
    Tree tree(10) ; 
    vector<int> bsftree = {32 ,21 , 42, 18 , 0 , 0 , 88, 14 , 0 , 78 , 92 , 0 , 0 ,66 , 0 , 0,0,0,73} ; 

    Tree mytree = tree.buildCustomTree(bsftree) ; 
    mytree.inorder() ; cout<<endl; 
    mytree.prettyPrint() ; 
    cout<<"Height : " << findHeight(mytree.getRoot()) ; 
}