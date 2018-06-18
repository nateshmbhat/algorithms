#include<bits/stdc++.h>
using namespace std; 

struct Node
{
    int data ; 
    Node * next ; 
};


class myList{

    Node * first , * head ;
    Node * get_first() ; 

    public : 
    myList(int data ) ; 

    Node * append(int data) ; 

    Node * prepend(int data) ; 
    Node * delete_end() ; 

    Node * delete_first();
    Node * delete_key(int key) ; 
    void sort() ;

    void Display() ; 
};