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

    Tree(int data = 0  ){
        root = new Node ; 
        root->l = root->r = 0 ;
        root->data = data ; 
        n = 1 ; 
    }

    friend std::ostream& operator<<(std::ostream& , Tree&) ; 

    void inorder(Node * = (Node *) -1 ) ;
    void preorder(Node * = (Node *) -1 ) ; 
    int findMax(Node * ) ; 
    bool isBST(Node * ) ; 
    void postorder(Node * = (Node *) -1 ) ; 
    void insertBST(int ) ;
    Tree generateRandBST(int ) ; 
    Tree generateRandBT(int) ; 

} ; 


#endif // !1 TREES_H