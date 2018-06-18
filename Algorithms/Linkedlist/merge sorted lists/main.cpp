#include<bits/stdc++.h>
#include"../utils.h"

using namespace std; 


void merge_lists(list<int> l1 , list<int> l2)
{

}


int main(void)
{
    srand(time(NULL)) ; 

    myList l1(10) , l2(20) ; 

    for(int i =0 ; i< 10 ; i++)
    {
        l1.append(rand()%20) ; 
        l2.append(rand()%20) ;
    }

    l1.Display() ; 
    l2.Display() ; 

    l1.sort(); 
    l2.sort() ; 
    l1.Display() ; 
    l2.Display() ;

}