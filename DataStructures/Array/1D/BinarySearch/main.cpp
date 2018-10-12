#include<bits/stdc++.h>
#include "../utils.h"
#include "../utils.cpp"

using namespace std; 


template<class Type>
int binary_search(vector<Type> A, int l  , int h , int k )
{
    if(l>h) return -1 ; 

    int mid = (l+h)/2 ;
    if(k==A[mid])
        return mid ; 
    if(k<A[mid])
       return binary_search(A , l , mid-1 , k) ; 
    else
        return binary_search(A , mid+1 , h  , k) ; 
}


int main(void)
{
    MyArray<int> arr(10 , true ); 
    cout<<arr<<endl; 
    cout<<"Enter key : " ; 
    int key ; cin>>key ;
    int res =  binary_search(arr.A , 0 , arr.A.size() -1 , key ) ; 
    cout<<" = > " << res ; 
}