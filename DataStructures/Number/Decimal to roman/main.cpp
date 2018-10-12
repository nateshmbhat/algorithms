#include<bits/stdc++.h>
using namespace std ;

void dec_to_roman(int n )
{
    unordered_map<int , string>  M = {{500 , "D"} ,{400 , "CD"} , {100 , "C"} , {90 , "XC"} , {50 , "L"} , {40 , "XL"} , {10 , "X"} , {9 ,"IX"} , {5 , "V"}, {4, "IV"} , {1 , "I"} } ; 

    string res , temp; 
    int order = 100 , k ; 

    while(n)
    {
       temp = M[(n/order)*order]  ; 
       if(temp!="") res+=temp ; 

       else{
           k = (n/order) ;
           for(int i=0 ; i<k ; i++)
                res+=M[order] ; 
       }
       n%=order ; order/=10 ;
    }

    cout<<res ; 
}


int main(void)
{
    int n = 343 ; 
    dec_to_roman(n) ; 
}