#include<bits/stdc++.h>
using namespace std; 



void find_nth_look_and_say_helper(string res , int n )
{
    cout<<res<<endl; 
    if(n==0){ return ; }

    string newstring ; int temp ; 
    for(int i =0   ; i<res.length() ; i+=temp)
    {
        temp  = 1; 
        while(i+temp<res.length() && res[i]==res[i+temp])
            temp++ ; 
        newstring+= (to_string(temp)+res[i]) ; 
    }
    find_nth_look_and_say_helper( newstring , n-1) ; 
}



void find_nth_look_and_say(int n )
{
    string res= "1";
    find_nth_look_and_say_helper(res, n);
}



int main(void)
{
    int n = 10 ; 
    find_nth_look_and_say(n) ; 
}