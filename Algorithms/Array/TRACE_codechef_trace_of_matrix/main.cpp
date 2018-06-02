#include<bits/stdc++.h>
using namespace std ;

int main(void)
{
    int T , M[100][100]  , k , i , j , max_sum  , N  ,temp_sum                                          ;
    cin>>T ; 
    for(int t =0 ; t<T ; t++ )
    {
        max_sum = numeric_limits<int>::min() ; 
        cin>> N ; 

        for(int i =0 ; i <N ; i++  )
            for(int j = 0 ; j< N ; j++)
                cin>>M[i][j] ; 
        

        for(int i = 1 ; i<N ; i++ )  
        {
            for(int j =1 ; j<N ; j++ )
                max_sum = max(max_sum , M[i-1][j-1] + M[i][j] ) ; 
        }

        cout<<max_sum<<endl; 
    }
}