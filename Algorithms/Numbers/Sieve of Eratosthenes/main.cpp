#include<bits/stdc++.h>

using namespace std  ;

void Eratosthenes(int n )
{
    bool a[100]  ;
    memset(a , 1 , 100) ;

    for(int i = 2 ; i<=sqrt(n) ; i++)
    {
        for(int j=i*i ; j<n ; j+=i)
           a[j]=0 ;
    }

    for(int i=2 ; i<n ; i++)
    {
        if(a[i])
            cout<<i <<" " ;
    }
}


int main(void)
{
    int n  ;
    cout<<"Enter n : " <<endl ;
    cin>>n ;

    Eratosthenes(n) ;
}
