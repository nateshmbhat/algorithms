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
    }

    friend std::ostream& operator<<(std::ostream& , Tree&) ; 

    void inorder(Node *) ;
    void preorder(Node * ) ; 
    int findMax(Node * ) ; 
    bool isBST(Node * ) ; 
    void postorder(Node * ) ; 
    void insertBST(int ) ;
    Tree generateRandBST(int ) ; 
    Tree generateRandBT(int) ; 

} ; 


#endif // !1 TREES_H