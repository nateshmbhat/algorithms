#include<bits/stdc++.h>

using namespace std; 

int main(void)
{
    vector<int> a = {1,5,2,8 , 10 , 7 , 6 } ; 
    for(int i =0 ; i<a.size()-1 ; i++)
    {
        if(i&1)
        {
            if(a[i]>a[i+1])
                swap(a[i] , a[i+1]) ; 
        }
        else
            if(a[i]<a[i+1])
                swap(a[i] , a[i+1]) ; 
    }
    for(int i : a) cout<<i <<' ' ; 
}

