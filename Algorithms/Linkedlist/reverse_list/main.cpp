#include<bits/stdc++.h>
#include"../utils.h"
using namespace std; 


void reverse(myList&  l)
{ Node * first = l.get_first()  , *rev = 0  , * temp = first->next ; 
    while(temp)
    {
        first->next = rev ; 
        rev = first ; 
        first =  temp ; 
        temp = temp->next ; 
    }

    first->next = rev ; 
    l.setFirst(first) ;  
}


int main(void)
{

    myList l1 ; 
    list<int> l2 ; 
    for(int i =0 ; i< 10 ; i++)
        l2.push_back(i) ; 
    
    for(auto i : l2 )
        cout<<i <<" -> " ;
    cout<<endl<<endl; 

    reverse(l2.rbegin() , l2.rend()) ; 
    
    for(auto i : l2 )
        cout<<i <<" -> " ;
    cout<<endl<<endl; 

    cout<<endl<<endl; 

    for(auto i : l2 )
        cout<<i <<" -> " ;
    

    l1.populateList(10) ; 
    l1.Display() ; 
    reverse(l1) ;
    l1.Display() ; 
}