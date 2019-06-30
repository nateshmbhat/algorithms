#include<bits/stdc++.h>
using namespace std; 

void reversewords(string s)
{
    reverse(s.begin() ,s.end());
    int start =0  , pos = 0 ; 

    while( (pos=s.find(' ' , start))!=string::npos )
    {
        reverse(s.begin() + start , s.begin() + pos ) ; 
        start = pos+1 ; 
    }

    reverse(s.begin() + start , s.end() ) ; 

    cout<< s ; 
}


int main(void)
{
    string s = "Hello this is my string" ; 
     reversewords(s) ; 
}