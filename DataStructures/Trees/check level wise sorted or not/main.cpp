#include<bits/stdc++.h>
#include"../utils.h"
using namespace std; 

bool checkIfLevelSorted(Node * root)
{
    queue<Node * > Q ; Q.push(root) ;
    int minel = root->data , maxel = root->data ;

    while(!Q.empty())
    {
        int size = Q.size() ; 
        
        for(int i =0 ; i < size ; i++)
        {
           Node * left = Q.front()->l , *right = Q.front()->r  ;  

           if(left) {
               if(left->data < maxel)  return false ; 
               maxel = left->data ; 
               Q.push(left) ; 
           }
           if(right){
               if(right->data < maxel ) return false ; 
               maxel = right->data ; 
               Q.push(right) ; 
           }
           Q.pop() ; 
        }
    }

    return true ; 
}


int main(void)
{
    Tree t(50) ; 
    vector<int> a = {1 , 2, 3, 4, 5 , 6 , 8 , 9 , 9  } ; 

    Tree tree = t.buildCustomTree(a) ; 

    tree.prettyPrint() ; 
    cout<< (checkIfLevelSorted(tree.getRoot())?"True" : "false" ) <<endl;  
}