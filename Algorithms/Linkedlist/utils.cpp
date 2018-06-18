#include<bits/stdc++.h>
#include"utils.h"

using namespace std ; 


void linkswap(Node * l1 , Node * l2 , Node * parent)
{
    l1->next = l2->next ; 
    l2->next = l1 ; 
    if(parent)
        parent->next = l2 ; 
}


myList::myList(int data ){
    head = new Node ; 
    head->data = 0 ;
    first = new Node ; 
    first->data = data ; 
    first->next = 0 ; 

    head->next = first ; 
}

    Node * myList::get_first(){return first ; }

    Node * myList::append(int data)
    {
       Node * temp = first ;  
       while(temp && temp->next )
            temp = temp->next ; 
       Node * newnode =  new Node ; 
       newnode->data = data ; 
       newnode->next =0 ; 
       head->data++ ; 
       if(!first) this->first = newnode ; 
       else 
           temp->next = newnode ; 
       return this->first ; 
    }


    Node * myList::prepend(int data)
    {
        Node *newnode = new Node ; 
        newnode->data =data ;
        newnode->next = first ;
        this->first = newnode ; 
        head->next = first ; 
        head->data++ ; 
        return this->first ; 
    }


    Node * myList::delete_end()
    {
        if(!first)
            {   cout<<"Overflow !" ;return first ;  }
        if(!first->next){
            delete first ; 
            first = 0 ; 
        }
        
        Node * parent = first  , * temp  = first->next ; 
        while(temp->next)
        {
            parent = temp ; 
            temp = temp->next ; 
        }

        parent->next = 0 ; 
        delete temp ; 
        head->data-- ; 
        return first ; 
    }



    Node * myList::delete_first()
    {
        if(!first) {cout<<"Empty List !" ; }
        else{
            if(!first->next){delete first ; first = 0 ; return first ; }

            Node *  temp = first ; 
            first = first->next ; 
            delete temp ; 
            head->data-=1 ; 
            return first ; 
        }
    }



    Node * myList::delete_key(int key)
    {
        Node*  temp = first  , * parent = first ; 

        while(temp && temp->data!=key)
        {
            parent = temp ; 
            temp = temp->next ; 
        }

        if(!temp)
            {cout<<"Key not found !" ; }
        else{
            parent->next = temp->next ; 
            head->data-=1 ; 
            delete temp ; 
        }
        return first ; 
    }



    void myList::sort()
    {
        Node * temp = first ,* parent = 0 ; 

        for(int i =0 ; i<head->data - 1 ; i++)
        {
            parent = 0 ; 
            temp = first ;
            for(int j =0   ; j<head->data-i ; j++)
            {
                if(temp->data > temp->next->data) 
                {
                    if(temp==first && j==0) first = temp->next ; 
                    linkswap(temp , temp->next , parent) ; 
                    if(!parent)
                        parent = first ; 
                    else parent = parent->next ; 
                }
                else{
                    parent = temp ; 
                    temp=temp->next ;   
                }

            }
        }        
    }



    void myList::Display()
    {
        cout<<endl ; 
        for(Node *  temp = first ; temp ; temp= temp->next )
        {
            cout<<temp->data <<" -> " ;             
        }
        cout<<endl<<endl; 
    }
