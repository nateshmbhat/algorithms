#include"../utils.h"
#include<bits/stdc++.h>


using namespace std ; 


struct res {
    int key ; 
    int num ; 
} ; 



res utilFunc(Node * root)
{
    if(!root->l && !root->r)return res({root->data , 1}) ; 

    res left , right ; 

    if(root->l) left = utilFunc(root->l) ; 
    if(root->r) right = utilFunc(root->r) ; 

    if(!root->l) left = res({root->data , 0}) ; 
    if(!root->r) right = res({root->data , 0}) ; 

    if(left.key == right.key && right.key==root->data && root->data>0){
        return res({left.key , left.num+right.num+1 }) ; 
    }
    else return res({-1 , left.num+right.num}) ; 
}


int totalUniversalValues(Node * root)
{
    res result = utilFunc(root) ; 
    return result.num ; 
}



int main(void)
{
    Tree t = Tree() ; 
    // vector<int> a = {1 , 2 , 1 ,0,0, 2 , 1  , 2, 2} ; 
    vector<int> a = {3 , 0 , 3 , 0 , 3 , 0 ,3} ; 
    Tree mytree = t.buildCustomTree(a)  ;

    mytree.prettyPrint() ; 

    int res = totalUniversalValues(mytree.getRoot() ) ; 
    cout<<"\nresult = " <<res <<endl; 
}