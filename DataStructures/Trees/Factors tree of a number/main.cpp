#include"../utils.h"
#include<bits/stdc++.h>
using namespace std; 

struct node{
    int data ; 
    struct node * l , * r ; 
} ; 

// bool isPrime(int n ){
//     if(n==1) return false ;
//     if(n==2) return true ; 
//     for(int i =2 ; i <=sqrt(n) ; i++)
//         if(n%i==0) return false ; 
//     return true ; 
// }

node * getFactorTree(int n)
{
    node * root = new node() ; root->data = n ; 
    if(n<=2) return root ; 

    int i = 2 ; 

    for( ; i <= sqrt(n) ; i++)
    {
        if(n%i==0)break ; 
    }

    if(i>sqrt(n)) return root ; 
    
    root->l = getFactorTree(i) ;
    root->r = getFactorTree(n/i) ; 
    return root ; 
}


void treeprint(node * root)
{
    if(!root) return ; 
    cout<< root->data <<" " ; 
    treeprint(root->l) ; 
    treeprint(root->r) ; 
}


int main(void)
{
    node * root = getFactorTree(48) ; 
    treeprint(root) ; 
}