#include<bits/stdc++.h>

using namespace std ; 


void prime_factors(int n )
{
    while(n%2==0)
    {
        cout<<2<<" " ;
        n/=2 ; 
    }

    for(int i =3  ; i<=sqrt(n) ; i++)
    {
        if(n%i==0)
            {
                cout<<i <<" " ; 
                n/=i ; 
            }
    }

    if(n>1) cout<<n ;
    
}


int main(void)
{
    int n ; cout<<"Enter n : " ; 
    cin>>n ; 
    prime_factors(n) ;
}