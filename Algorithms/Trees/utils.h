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
    friend std::ostream& operator<<(std::ostream& , Tree&) ; 

    Node * getRoot() ; 
    void inorder(Node * = (Node *) -1 ) ;
    void prettyPrint(int = 60) ; 
    void preorder(Node * = (Node *) -1 ) ; 
    int findMax(Node * ) ; 
    bool isBST(Node * ) ; 
    void postorder(Node * = (Node *) -1 ) ; 
    void insertBST(int ) ;
    Tree generateRandBST(int  , int = 0 , int = 100) ; 
    Tree generateRandBT(int) ; 

} ; 


#endif // !1 TREES_H