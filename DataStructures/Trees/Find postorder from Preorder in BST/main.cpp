#include<bits/stdc++.h>
#include"../utils.h"
using namespace std; 

void PostOrder(vector<int> preorder , int start , int end) 
{
    if(start>end) return ; 
    int partitionIndex =start+1 ; 
    int root = preorder[start] ; 

    if(start<end)
    {
        while(partitionIndex<=end && preorder[partitionIndex]<root) partitionIndex+=1 ; 
        if(partitionIndex>=start+2) PostOrder(preorder , start+1 , partitionIndex-1) ; 
        PostOrder(preorder , partitionIndex, end ) ; 
    } 

    cout<< root << " " ; 
    if(preorder.size()==(end-start)+1) cout<<endl; 
}


int main(void)
{
    vector<int> preorder = {30 , 20 , 16 , 19 , 25 , 45 , 33 , 50 } ; 
    // Answer = {19  , 16 , 25 , 20 , 33 , 50 , 45 ,  30 } ; 
    PostOrder(preorder , 0 , preorder.size()-1) ; 
}