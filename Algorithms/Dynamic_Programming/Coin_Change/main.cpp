#include<bits/stdc++.h>
using namespace std ;

/*

Given a value N, find the number of ways to make change for N cents, if we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins. 
The order of coins doesn’t matter. 
Example : 
for N = 4 and S = {1,2,3}, 
There are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. 
So output should be 4. 

For N = 10 and S = {2, 5, 3, 6} 
There are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. 

So the output should be 5.


*/

int N ; //Total Sum
int arr[1000] ; 
int n ; //array size
int mem[100][100] = {0} ; 

int getCoins(int i , int total ){
    if(mem[i][total]>0) return mem[i][total] ; 

    if(total==0) return 1 ; 
    if(i>=n || total<0) return 0 ; 

    int incl = getCoins( i , total-arr[i]) ; 
    int excl = getCoins( i+1 , total) ; 

    mem[i][total] = incl + excl ;  
    return mem[i][total] ; 
}

int getCoinsBottomUp(){
   int m[100][100] = {0} ;  
   for(int i = 0 ;i <= n ; i++) m[i][0] = 1 ; 
   for(int i = 1 ;i<=N ; i++) m[0][i] = 0 ; 

   for(int i=1 ; i<=n ;i++){
       for(int j =1 ; j<=N ; j++ ){
           if(j>=arr[i-1]) m[i][j] = m[i][j-arr[i-1]] ; 
           m[i][j]+= m[i-1][j]; 
       }
   }

    return m[n][N] ; 
}

int main(){
    N = 4 ; 
    n = 3 ; 
    arr[0] = 1 , arr[1]  = 2 , arr[2] = 3 ; 

    cout<< getCoinsBottomUp() << endl;
}
