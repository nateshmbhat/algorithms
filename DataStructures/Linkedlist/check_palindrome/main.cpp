#include<bits/stdc++.h>
#include"../utils.h"
using namespace std; 

Node * reverse(Node * firstNode)
{ Node * first = firstNode  , *rev = 0  , * temp = first->next ; 
    while(temp)
    {
        first->next = rev ; 
        rev = first ; 
        first =  temp ; 
        temp = temp->next ; 
    }

    first->next = rev ; 
    return first ; 
}


bool check_palindrome(myList l)
{
    Node * first = l.get_first() ; 
    Node * slow =first ,  * fast = first ; 
    while(fast && fast->next) {slow = slow->next ; fast = fast->next->next ; }
    Node * second_haf =  reverse(slow)  , * second_haf_copy = second_haf; 
    
    while(second_haf->next )
    {
        if(first->data !=second_haf->data){
            reverse(second_haf_copy) ; 
            return false ; 
       }
        first = first->next ; second_haf = second_haf->next ; 
    }
    
    reverse(second_haf_copy) ; 
    return true ; 
}


int main(void)
{
    myList l1 , l2  ; 
    for(int i =0 ; i< 5 ; i++) l1.append(i) ; 
    for(int i =5 ; i>=0 ; i--) l1.append(i) ; 

    l2.populateList(10) ; 

    l1.Display() ; 
    cout<< (check_palindrome(l1) ? "Palindrome " : "Not palindrome " ) ;
    l1.Display() ;
    l2.Display() ; 
    cout<< (check_palindrome(l2) ? "Palindrome " : "Not palindrome ") ;
    l2.Display() ; 
}