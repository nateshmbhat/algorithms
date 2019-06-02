// https://practice.geeksforgeeks.org/problems/cutted-segments/0
#include <iostream>
#include<bits/stdc++.h>

using namespace std ;

int mem[10000]  ; 

int solve(int N , int x , int y , int z){
    
    if(N<0) return INT_MIN ; 
    if(N==0)return 0 ;
    if(mem[N]>=0) return mem[N] ;
    
    int res = 0 ;
    
    res = 1 + solve(N-x , x  , y , z) ;
    res = max(res , 1+solve(N-y , x ,y , z)) ; 
    res = max(res , 1+solve(N-z , x , y , z)) ;
        
    mem[N] = res ;
    return res ;
}

int bottomup(int N , int x , int y , int z){
    
    mem[0] = 0 ;

    for(int i =1 ; i <= N  ; i++ )
    {
        int res = -1 ; 
        if(x<=i && mem[i-x]>-1) res = 1 + mem[i-x] ; 
        if(y<=i && mem[i-y] >-1 ) res = max(res ,1+ mem[i-y] ); 
        if(z<=i && mem[i-z]>-1) res = max(res ,1+ mem[i-z] ); 
        if(i<x && i<y && i<z) res = INT_MIN ; 
        mem[i] = res ; 
    }

    return mem[N] ; 
}

int main() {

	int t ; cin>>t ; 
	
	for(int _= 0 ; _< t; _++){
	    int N  ; cin>>N ;
	    int x , y , z ; 
	    cin>>x >>y >>z ;
	    memset(mem , -1 , 10000*sizeof(int)) ;	
	    cout<< bottomup(N , x , y , z) <<endl; 
	}
}