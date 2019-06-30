#include<bits/stdc++.h>
// https://www.geeksforgeeks.org/given-two-sorted-arrays-number-x-find-pair-whose-sum-closest-x/

using namespace std ; 


void findclosepair( const vector<int> & ar1 , const vector<int> & ar2 , int n)
{
    int l =0 , r = ar2.size()-1 ; 
    int diff = INT_MAX , p1, p2 ; 

    while(l<r)
    {
        int curdiff = abs(ar1[l]+ar2[r] - n ) ;
        if(curdiff<diff)
        {
            diff = curdiff ; 
            p1 = l , p2 = r ;
        }
        else if(ar1[l]+ar2[r]<n)
            l++ ; 
        else r-- ; 
    }

    cout<< ar1[p1]<<"  " << ar2[p2] ; 
}


int main(void)
{
    vector<int> ar1= {1, 4, 5, 7};
    vector<int> ar2 =  {10, 20, 30, 40};
    int n = 32 ;

    findclosepair(ar1 , ar2 , n) ;
}