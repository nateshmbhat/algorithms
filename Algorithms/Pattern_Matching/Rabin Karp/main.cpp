#include<bits/stdc++.h>

using namespace std; 

long getHash(string s)
{
    int base = 10 ;
    long sum = 0 ; 
    for(int i =0 ; i<s.length() ; i++)
    {
        sum+= s[i] * pow(base , i) ; 
    }
    return sum ; 
}

long getRolling( long cur , char old , char newchar , int len)
{
   cur-=old ;  
   cur/=10 ;
   cur+= newchar * pow(10 , len) ; 
   return cur ; 
}


int main(void)
{
    string t = "ababccdcabaaccd" ; 
    string p = "abaac" ; 

    long phash = getHash(p) ; 
    long cur = getHash(t.substr(0 , p.length())) ; 

    for(int i =0 ; i <= t.length() - p.length() ; i++)
    {
        if(phash == cur){
            if(p==t.substr(i , p.length()))
                cout<< " Found at : " << i ; 
        }

        cur = getRolling(cur , t[i] , t[p.length()+i] , p.length()-1) ; 
    }
}