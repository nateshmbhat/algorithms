#include<bits/stdc++.h>
#include"../utils.h"
using namespace std; 

int main(void)
{
    Tree tree(10) ; 
    vector<int> inorder = {4 , 5 , 1, 2, 10 , 7  , 9 } ; 
    vector<int> preorder = {2 , 1, 4 , 5 , 7 , 10 , 9} ; 
    tree.buildTreeFromInorderPreorder(inorder , preorder) ; 
    tree.prettyPrint() ; 
}