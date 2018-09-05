#include<bits/stdc++.h>

using namespace std ; 

template <class T>
struct Node
{
    T data ; 
    Node<T> * next ; 
};


template<class T>
class List{


    public : 

    List(T data ){
        first = new Node<T> ; 
        first->data = data ; 
        first->next = 0 ; 
    }

    Node<T> * get_first(){return first ; }

    Node<T> * append(T data)
    {
       Node<T> * temp = first ;  
       while(temp && temp->next )
            temp = temp->next ; 
       Node<T> * newnode =  new Node<T> ; 
       newnode->data = data ; 
       newnode->next =0 ; 
       if(!first) this->first = newnode ; 
       else 
           temp->next = newnode ; 
       return this->first ; 
    }

    Node<T> * prepend(T data)
    {
        Node<T> *newnode = new Node<T> ; 
        newnode->data =data ;
        newnode->next = first ;
        this->first = newnode ; 
        return this->first ; 
    }

    Node<T> * delete_end()
    {
        if(!first)
            {   cout<<"Overflow !" ;return first ;  }
        if(!first->next){
            delete first ; 
            first = 0 ; 
        }
        
        Node<T> * parent = first  , * temp  = first->next ; 
        while(temp->next)
        {
            parent = temp ; 
            temp = temp->next ; 
        }

        parent->next = 0 ; 
        delete temp ; 
        return first ; 
    }


    Node<T> * delete_first()
    {
        if(!first) {cout<<"Empty List !" ; }
        else{
            if(!first->next){delete first ; first = 0 ; return first ; }

            Node<T> *  temp = first ; 
            first = first->next ; 
            delete temp ; 
            return first ; 
        }
    }

    Node<T> * delete_key(T key)
    {
        Node<T>*  temp = first  , * parent = first ; 

        while(temp && temp->data!=key)
        {
            parent = temp ; 
            temp = temp->next ; 
        }

        if(!temp)
            {cout<<"Key not found !" ; }
        else{
            parent->next = temp->next ; 
            delete temp ; 
        }
    }



    void Display()
    {

        cout<<endl ; 
        for(Node<T> *  temp = first ; temp ; temp= temp->next )
        {
            cout<<temp->data <<" -> " ;             
        }
        cout<<endl<<endl; 
    }

} ; 




int main(void)
{
    List<int> L(20) ; 
    for(int i=0 ; i<10 ; i++)
        L.append(i) ;  

    L.Display() ; 
    L.delete_end() ;
    L.Display() ; 
    L.delete_first() ;
    L.Display() ; 
    L.delete_key(5) ; 
    L.Display() ; 
    L.prepend(100) ; 
    L.Display() ; 
}