#include<bits/stdc++.h>

using namespace std ; 

void pascal(int n )
{
    vector<vector<int>> P ; 
    for(int i =0 ; i<n ; i++)
    {
        vector<int> row ; 

        for(int j = 0 ; j<=i ; j++)
        {
            row.push_back((j<i && j>0)? P[i-1][j-1]+ P[i-1][j] : 1) ; 
        }
        P.push_back(row) ; 
    } 
}


int main(void)
{
    pascal(10) ; 
}