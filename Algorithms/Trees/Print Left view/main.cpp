#include<bits/stdc++.h>
#include"../utils.h"
using namespace std; 


void printLeftView(Node * root){
    while(root && root->left){
        cout<< root->left ; 
    }
}

int main(){
    Tree mytree = *new Tree() ; 
    mytree.generateRandBST(10) ; 
    cout<<"Inorder : "  ; mytree.inorder()  ; cout <<endl; ; 
    cout<<"Preorder : "  ;mytree.preorder() ; cout<<endl; 
    mytree.prettyPrint() ;

    printLeftView(mytree.getRoot()) ;
}
