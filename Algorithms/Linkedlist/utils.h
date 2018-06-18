#include<bits/stdc++.h>
using namespace std; 

#pragma once 
struct Node
{
    int data ; 
    Node * next ; 
};


class myList{

    Node * first , * head ;

    public : 

    myList(int =0 ) ; 
    void setFirst(Node * ) ; 
    Node * get_first() ; 
    Node * populateList(int , int =0  , int  = 30) ; 

    Node * append(int data) ; 

    Node * prepend(int data) ; 
    Node * delete_end() ; 

    Node * delete_first();
    Node * delete_key(int key) ; 
    void sort() ;

    void Display() ; 
};