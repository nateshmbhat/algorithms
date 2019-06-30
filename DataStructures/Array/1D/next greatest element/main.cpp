#include<bits/stdc++.h>

using namespace std ; 

int main(void)
{

    int a[] ={4,6,34,45,54,2,56,54,44,88 , 34 ,38 , 5 , 3 , 8} ; 
    int n = sizeof(a)/sizeof(a[0]) ; 
    int out[100] ; 

    int max_yet = a[n-1] ; 

    for(int i = n-1 ; i>=0 ; i--)
    {
        out[i] = max_yet ; 
        if(a[i]>max_yet)
        {
            max_yet = a[i] ;
        }

    }

    for(int j =0 ; j<n ; j++)
        cout<<out[j] <<" " ;   
}