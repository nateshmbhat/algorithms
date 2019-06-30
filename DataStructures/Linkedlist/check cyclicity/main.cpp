#include<bits/stdc++.h>
#include"../utils.h"
using namespace std; 

int checkCycle(myList L )
{
    Node * slow = L.get_first() , * fast = L.get_first() ; 
    while(fast->next && slow){
        slow = slow->next  ; fast = fast->next->next ; 
        if(slow==fast)
        {
            slow = L.get_first() ; 
            int count = 0 ; 
            while(slow!=fast) {slow = slow->next ; fast = fast->next ; count ++ ;  }
            return count + 1 ; 
        }
    }
    return 0 ;
}


void makeCycle(myList L , int joint ){
    Node * temp = L.get_first() ; 
    Node * jointptr = L.get_head() ; 
    while(joint-- && jointptr) jointptr= jointptr->next ; 
    while(temp && temp->next) temp = temp->next ; 
    temp->next = jointptr ; 
}


int main(void)
{
    myList L ;
    L.populateList(15) ;
    L.Display() ; 
    makeCycle(L , 7 ) ; 
    cout << "cycle at " << (checkCycle(L)) <<endl; 
}
