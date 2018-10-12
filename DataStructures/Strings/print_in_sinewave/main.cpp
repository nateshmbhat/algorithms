#include<bits/stdc++.h>
using namespace std ; 

int main(void)
{
    string s = "Hello its me ! " ; 
    vector<char> a , b , c; 
    
for(int i =1 ; i<s.length() ; i+=4)
    {
        a.push_back(s[i]) ;
    }
for(int i =0 ; i<s.length() ; i+=2)
    {
       b.push_back(s[i]) ;  
    }
for(int i =3 ; i<s.length() ; i+=4)
    {
       c.push_back(s[i]) ; 
    }

    cout<<'\t' ; 
    for(char i: a)
        cout<<i<<"\t\t\t\t" ; 
    cout<<endl; 

    for(char i: b)
        cout<<i<<"\t\t" ; 

    cout<<endl<<"\t\t\t" ; 
    for(char i: c)
        cout<<i<<"\t\t\t\t" ; 

    cout<<endl; 
}