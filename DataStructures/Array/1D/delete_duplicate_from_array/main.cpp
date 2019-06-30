#include<bits/stdc++.h>
using namespace std;  

int main(void)
{
    vector<int> A = {2 , 3 , 5,5,7,11,11,11,11,13} ; 
    int r = 1 , w = 1 ; 
    for ( ;  w<A.size() ; )  
    {
        if(A[w]!=A[w-1])
            {A[r++] = A[w++] ; }
        else w++ ;
    }
    for(int i=0 ; i<A.size() ; i++)
        cout<<A[i]<<' ' ; 
}