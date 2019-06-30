#include<bits/stdc++.h>
#include"../utils.h"
using namespace std; 

/* 
Input list : 
3 -> 1 -> 4 ->

7 -> 0 -> 9 ->

413 + 907 = 1320


Output : 

Sum =
0 -> 2 -> 3 -> 1 ->

 */

myList addStuff(myList A  , myList B)
{
    myList res ; 
    Node * Atemp = A.get_first() , *Btemp = B.get_first() ; 
    int c = 0 ;
    while(Atemp || Btemp)
    {
        int tempsum = (Atemp?Atemp->data:0) + (Btemp? Btemp->data : 0)  + c ; 
        c = tempsum/10 ; 
        res.append(tempsum%10) ; 
        if(Atemp)Atemp = Atemp->next ; if(Btemp)Btemp = Btemp->next ; 
    }
    
    if(c) res.append(c)  ; 
    return res ;  
}

int main(void)
{
    myList A , B ; 
    A.append(3);A.append(1) ; A.append(4) ; 
    B.append(7);B.append(0) ; B.append(9) ; 
    A.Display() ; 
    B.Display() ; 
    cout<<"\nSum = " <<endl; 
    myList res = addStuff(A , B) ; 
    res.Display() ; 
}