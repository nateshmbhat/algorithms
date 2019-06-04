#include<bits/stdc++.h>

using namespace std ; 


void Matrixrotate(vector<vector<int>> M )
{
    vector<vector<int>>R = M ; 

    int k = 0 ; 
    for(int i =0 ; i<M.size() ; i++ )
    {
        for(int j =0 ; j<M[i].size() ; j++ )
        {
           k = M.size()-i - 1 ; 
           R[M.size()-i-1][j] = M[i][j] ;  
        }
    }

    for(vector<int> i : R)
    {
        for(int j : i )
        {
            cout<<j <<" " ; 
        }
        cout<<endl; 
    }
}


int main(void)
{
    vector<vector<int>> M = {{1 , 2, 3} , {4 , 5, 6} , {7 , 8 , 9 }} ; 
    Matrixrotate(M) ;
}