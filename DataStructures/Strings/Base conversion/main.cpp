#include<bits/stdc++.h>
using namespace std; 


string convert(string s, int b1 , int b2)
{
    char REF[] = "0123456789ABCDEF" ; 
    long int sum =0 , power = 1 ; 
    for(int i =s.length()-1 ; i>=0 ; i--)
    {
       sum+= power * (s[i]-'0') ; 
       power*=b1 ; 
    }
    string ans ;
    while(sum)
    {
        ans+=REF[sum%b2] ; 
        sum/=b2 ;
    }
    
    string res = {ans.rbegin() , ans.rend() } ; 
    return res ; 
}


int main(void)
{
    string s ; int b1 , b2 ; 
    cin>>s>>b1>>b2 ; 
    cout<< convert(s , b1 , b2) <<endl; 
}