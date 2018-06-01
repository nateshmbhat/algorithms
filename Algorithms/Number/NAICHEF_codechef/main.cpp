#include<bits/stdc++.h>
using namespace std ; 

int main(void)
{
    int T  , N , A , B , temp , A_count =0 ,B_count=0  ; 

    cin>> T ; 
    for(int t =0 ; t< T ; t++)
    {

        cin>> N >> A >> B; 
        A_count = B_count = 0 ;         
        for(int i =0 ; i<N ; i++ )
            { 
                cin>>temp ; 
                if(temp==A)A_count+=1  ; 
                if(temp==B) B_count+=1  ; 
            }

        cout<<A_count/double(N) * B_count/double(N)<<endl; 
        
    }
}