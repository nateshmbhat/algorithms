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
    srand(time(NULL)) ; 
    head = new Node ; 
    head->data = 0 ;
    head->next = 0 ; 
    first =0 ; 
}

Node * myList::get_head() { return head ; }

void myList::setFirst(Node * firstvar){first = firstvar ; }

    Node * myList::populateList(int n , int l , int h )
    {

        for(int i =0 ; i< n ; i++)
        {
            this->append(rand()%(h-l+1) + l) ; 
        }

        return get_first() ; 
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

        head->next = first ;
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
        head->next = first ; 
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
        head->next = first ; 
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
            head->next = first ; 
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
        head->next = first ; 
        return first ; 
    }



    void myList::sort()
    {
        Node * temp = first ,* parent = 0 ; 

        for(int i =0 ; i<head->data - 1 ; i++)
        {
            parent = 0 ; 
            temp = first ;
            for(int j =0   ; (j<head->data-i ) && temp->next ; j++)
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

        head->next = first ; 
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
