#include<bits/stdc++.h>
#include"../utils.h"
using namespace std; 

/* Given a binary tree and the two nodes say ‘a’ and ‘b’, determine whether two given nodes are cousins of each other or not.

Two nodes are cousins of each other if they are at same level and have different parents.

     6
   /   \
  3     5
 / \   / \
7   8 1   3
Say two node be 7 and 1, result is TRUE.
Say two nodes are 3 and 5, result is FALSE.
Say two nodes are 7 and 5, result is FALSE. */

bool checkIfBoolean(Node * root , int data1 , int data2)
{
    queue<Node * > Q ; 
    Node * bpar = 0  , * apar = 0  , *a  = 0 , *b  = 0 ; 
    Q.push(root) ; 

    while(!Q.empty())
    {
        a = 0 ; b = 0 ; 
        int size = Q.size() ; 
        for(int i =0 ; i < size ; i++)
        {
            if(Q.front()->l && Q.front()->l->data == data1) {apar = Q.front() ; a = Q.front()->l ;  }                        
            if(Q.front()->l && Q.front()->l->data == data2) {bpar = Q.front() ; b = Q.front()->l ;  }                        
            if(Q.front()->r && Q.front()->r->data == data1) {apar = Q.front() ; a = Q.front()->r ;  }                        
            if(Q.front()->r && Q.front()->r->data == data2) {bpar = Q.front() ; b = Q.front()->r ;  }                        
            if(Q.front()->l) Q.push(Q.front()->l) ; 
            if(Q.front()->r) Q.push(Q.front()->r) ; 
            Q.pop() ; 
        }

        if(a && b) break ; 
   }

    if(apar==bpar || a==0 || b==0 ) return false ;
    else return true ; 
}



int main(void)
{
    Tree t(50) ; 
    vector<int> a = {6 , 3 , 5 , 7 , 8 , 1 , 3 } ; 

    Tree tree = t.buildCustomTree(a) ; 
    cout<< (checkIfBoolean(tree.getRoot() , 3  , 8 )?"True" : "False") ; 
}