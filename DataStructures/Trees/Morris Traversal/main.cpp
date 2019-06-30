#include<bits/stdc++.h>
#include"../utils.h"
using namespace std; 


void morrisInorderTraversal(Node * root)
{
    Node * cur = root  , *pre ; 
    while(cur)
    {
        if(!cur->l){
            cout<< cur->data << ' ' ; 
            cur = cur->r ;  }

        else{
            pre = cur->l ; 
            while(pre->r && pre->r!=cur) pre= pre->r ; 

            if(!pre->r)
            {
                pre->r = cur ; 
                cur = cur->l ; 
            }
            else{
                pre->r = 0 ; 
                cout<< cur->data << " " ; 
                cur = cur->r ; 
            }
        }
    }
}



int main(void)
{

    Tree t(50) ; 
    t.generateRandBST(10) ; 
    t.inorder() ; cout<<endl; 
    morrisInorderTraversal(t.getRoot()) ; 
}