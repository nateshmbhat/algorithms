#include<bits/stdc++.h>

#ifndef TREES_H

#include<ostream>

class Node
{
    public : 

    int data ; 
    Node * l , * r ; 
   
    Node()
    {
        l = r  = 0 ; 
        data = 0; 
    }
};


class Tree
{
    public : 
    Node * root ; 
    int n ;  

    Tree(int = 0 ) ; 
    ~Tree() ; 
    friend std::ostream& operator<<(std::ostream& , Tree&) ; 

    Node * getRoot() ; 
    void setRoot(Node * ) ; 
    void deallocateAllNodes(Node *) ; 
    void inorder(Node * = (Node *) -1 ) ;
    void prettyPrint(int = 60) ; 
    void addNode(int) ; 
    void preorder(Node * = (Node *) -1 ) ; 
    
    Node * buildTreeFromInorderPreorder(std::vector<int> , std::vector<int> ) ; 

    static Tree buildCustomTree(std::vector<int>) ;
    int findMax(Node * ) ; 
    bool isBST(Node * ) ; 
    void postorder(Node * = (Node *) -1 ) ; 
    void insertBST(int ) ;
    Tree generateRandBST(int  , int = 0 , int = 100) ; 
    static Tree generateRandBT(int) ; 

    private : 
    Node * buildTreeFromInorderPreorderHelper(std::vector<int> , std::vector<int> , int ,int ,int,int ,std::unordered_map<int,int>& ) ; 

} ; 


#endif // !1 TREES_H