#include<bits/stdc++.h>

using namespace std ;

void fnFindMinJumps(int * arr , int n )
{
    int minjump[15] ,minjump_ref =0 , path[15] , path_ref =0 ;
//    for(int k = 0 ; k<15 ; k++) minjump[k] = 100000 ;
    fill(minjump,minjump+n , 10000) ;
    minjump[0] = path[0]  = 0 ;

    for(int i =1 ; i<n ; i++)
    {
        for(int j = 0 ; j<i ; j++)
        {
            if(j+arr[j]>=i)
            {
                minjump[i] = min(minjump[j]+1 , minjump[i]);
                path[i] = j ;
            }

        }
    }

    cout<<"Number of jumps = " << minjump[n-1] ;
}


int main(void)
{
    int arr[] = {2,4,3,2,1,5,6,1,2,1,2,5} ;
    int n = sizeof(arr)/sizeof(arr[0]) ;
    fnFindMinJumps(arr , n) ;
}
