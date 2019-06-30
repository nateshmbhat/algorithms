#include<bits/stdc++.h>
#include"../utils.h"
using namespace std;


bool checkIfMirrors(Node * root1 , Node * root2)
{
    if(!root1 && !root2) return true ; 
    else if (!root1 || !root2) return false ; 
    if(root1->data!=root2->data) return false ;
    return checkIfMirrors(root1->l , root2->r) && checkIfMirrors(root1->r , root2->l) ; 
}

int main(void)
{
    Tree t(50) ; 
    vector<int> a = {1 , 2, 3, 4, 5 , 6 , 7 , 8 , 9  } ; 
    vector<int> b = {1 , 3, 2, 7, 6 , 5 , 4 ,0,0,0,0,0,0, 9 , 8  } ; 

    Tree tree1 = t.buildCustomTree(a) ; 
    Tree tree2 = t.buildCustomTree(b) ; 

    tree1.prettyPrint() ; 
    tree2.prettyPrint() ; 
    cout<< (checkIfMirrors(tree1.getRoot() , tree2.getRoot())?"True" : "false" ) <<endl;   

}
