#include<bits/stdc++.h>
#include"../utils.h"

using namespace std; 


void merge_lists(myList l1 , myList l2)
{
    Node * p1 = l1.get_first() ; 
    Node * p2 = l2.get_first() , * temp ; 
    Node * s = p1->data <p2->data ? p1 : p2 ;
    s==p1 ? (p1 = p2->next) : (p2=p2->next) ; 


    while(p1 && p2)
    {
        if(p1->data < p2->data)
        {
            s->next = p1 ; 
            s = p1 ; 
            p1 = p1->next ; 
        }
        else{
            s->next = p2 ; 
            s = p2 ; 
            p2 = p2->next ; 
        }
    }

    s->next = p1 ? p1 : p2 ; 

}


int main(void)
{
    srand(time(NULL)) ; 

    myList l1, l2 ; 

    l1.populateList(10) ; 
    l2.populateList(10) ; 

    l1.sort(); 
    l2.sort() ; 
    l1.Display() ; 
    l2.Display() ;

    merge_lists(l1 , l2) ; 

    l1.Display() ; 
    l2.Display() ; 

}