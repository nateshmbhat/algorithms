#include<bits/stdc++.h>
#include "../utils.h"
#include "../utils.cpp"

using namespace std ; 

void Rotate(vector<int>& A ,int d )
{
    reverse(A.begin() , A.begin()+d ) ; 
    reverse(A.begin()+d , A.end()) ; 
    reverse(A.begin() , A.end()) ; 
}


int main(void)
{
    MyArray<int> A(4 , false , "random" , 1 , 15) ; 
    MyArray<int>B = A ; 
    cout<<A ; 
    Rotate(A.A , 1) ; 
    cout<<A ; 
    Rotate(B.A , 4 - 1) ; 
    cout<<B ; 
}