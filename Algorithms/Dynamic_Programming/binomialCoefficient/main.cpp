#include<bits/stdc++.h>

using namespace std ; 

int nCk(int n , int k ){

	int C[50][50] ={0} ; 

	for(int i =0 ;i <= n ; i++){
		for(int j =0 ; j <= min(i,k) ; j++){
			if(j==0 || i==j) 
				C[i][j] = 1; 
			else C[i][j] = C[i-1][j]+C[i-1][j-1] ; 
		}
	}
	
	return C[n][k] ; 
}



int main(void){
	int n , k ;
	cout<<"Enter n : " ; cin>>n ; 
	cout<<"Enter k : " ; cin>>k ; 
	cout<<"C(n,k) = " << nCk(n , k) <<"\n\n" <<endl; 
}