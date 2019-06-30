#include<bits/stdc++.h>
#include"../utils.h"
using namespace std; 


void printLeftView(Node * root){
    queue<Node*> myqueue ;     
    long int popcount = 1 ; 
    myqueue.push(root) ; 

    while(!myqueue.empty()){
        cout<< myqueue.front()->data << " " ; 
        int queuesize = myqueue.size() ; 
        for(int i =0 ; i< queuesize ; i++)
        {
         if(myqueue.front()->l) myqueue.push(myqueue.front()->l) ; 
         if(myqueue.front()->r) myqueue.push(myqueue.front()->r) ; 
         myqueue.pop() ; 
        }
    }
    cout<<endl<<endl;
}



int main(){
    Tree treeobj = *new Tree() ; 
    // mytree.generateRandBST(10) ; 
    vector<int> bsftree = {32 ,21 , 42, 18 , 0 , 0 , 88, 14 , 0 , 78 , 92 , 0 , 0 ,66 , 0 , 0,0,0,73} ; 

    Tree mytree = treeobj.buildCustomTree(bsftree) ; 

    cout<<"Inorder : "  ; mytree.inorder()  ; cout <<endl; ; 
    cout<<"Preorder : "  ;mytree.preorder() ; cout<<endl; 
    mytree.prettyPrint() ;
    printLeftView(mytree.getRoot()) ;
}
