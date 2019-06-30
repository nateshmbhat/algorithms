#include<bits/stdc++.h>
#include"../utils.h"
using namespace std; 


/*
Problem : 

Input : l0 -> l1 -> l2 -> l3 -> l4 ->  l5

Output : l0 -> l2 -> l4 -> l1 -> l3 -> l5
*/


void even_odd_merge(myList L )
{
    if(! L.get_first()->next) return ;
    Node * even = L.get_first() , *  odd = L.get_first()->next , *node_1 = L.get_first()->next ; 

    while(even&& odd)
    {
        even->next = odd->next ; 
        if(! even->next) break ; 
        even = even->next ;

        odd->next = even->next ; 
        odd = odd->next ; 
    }

    even->next =  node_1 ; 
}


int main(void)
{
    myList l1 ; 
    l1.populateList(9) ; 
    l1.Display() ; 
    even_odd_merge(l1) ; 
    l1.Display() ; 
}