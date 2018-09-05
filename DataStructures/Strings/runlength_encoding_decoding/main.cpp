#include<bits/stdc++.h>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std ; 


string encode(string s)
{
    string res ; int temp ; 
    for(int i =0 ; i<s.length() ; i+=temp)
    {
        temp = 1   ; 
        while(i+temp<s.length() && s[i]==s[i+temp])
            temp++ ; 
        char a[100] ; 
        sprintf(a , "%d" , temp) ; 
        string temps = a ; 
        res+= temps  + s[i]; 
    }
    return res ; 
}

string decode(string s )
{
    string res ; 
    for(int i =0 ; i<s.length() ; i+=2)
    {
        int n = s[i]-'0' ; 
        for(int j = 0 ; j<n ; j++)
            res+=s[i+1] ; 
    }
    return res ;
}

int main()
{
    
    string s = "aaaabcccdeefff" ; 
    string res = encode(s) ; 
    cout<<"Encoded : " << res ; 
    cout <<"\nDecoded : " << decode(res) ; 
}