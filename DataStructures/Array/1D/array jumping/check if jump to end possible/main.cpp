#include<bits/stdc++.h>
using namespace std;  


bool checkingFunction(vector<int> A)
{
    int furthest = A[0]  , i ; 

    for(i =0 ; i<A.size() ; i++ , furthest--)
    {
        if(max(furthest , A[i])<=0) return false ; 
        furthest = max(furthest , A[i]) ;
    }
    if(i==A.size()) return true ;
}



int main(void)
{
    vector<int> A = { 3,3,1,0 ,2,0,1} ; 
    vector<int> B = {3,2 , 0,0,2,0 , 1} ; 
    vector<int> C = {0 , 1} ; 
    cout<< checkingFunction(A)<<endl; 
    cout<<checkingFunction(B) <<endl; ; 
    cout<<checkingFunction(C ) ; 

}