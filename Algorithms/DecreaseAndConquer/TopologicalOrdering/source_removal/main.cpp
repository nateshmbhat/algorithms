#include<bits/stdc++.h>
#include<iostream>


using namespace std ;

void topologicalSort(int ** adj , int n)
{
	int * in = new int[n] ;
	int * out = new int[n] ;
	
	for(int i = 0 ; i < n ; i++)
	{
		for(int j = 0 ;j < n  ; j++){
			in[i]+=adj[j][i] ;
		}
	}
	
	bool flag = 0 ;
	int * stack = new int[100] ; int top = -1 ;
	int k = 0 ;
		
	while(1)
	{

		for(int i =0 ; i < n ; i++){
			if(in[i] ==0 ){
				stack[++top] = i ;				
				in[i]= -1 ;
			}
		
		}
		
		if(top==-1)break ;
		out[k] = stack[top--] ;
		for(int i =0 ; i <n ; i++){
			if(adj[out[k]][i]==1)
				in[i]-- ;
		}
		k++ ;
	
	}
	
	printf("Topological Sorting is : ") ; 
	for(int i =0 ;i < k ; i++)
		printf("%d " , out[i]+1) ;
	
	
	
}



int main(void)
{
	int * * adj  = {0} ; 
	
	int n ; 
	cout<<"Enter the number of vertices : " ; 
	cin>> n ; 
	
	adj = new int*[n] ; 
	for(int i =0 ; i < n ; i++)
		adj[i] = new int[n] ;
		
	cout<<"Enter adjancency matrix : " ;
	for(int i = 0 ; i < n ; i++)
		for(int j = 0; j < n ; j++)
			cin>>adj[i][j] ;
		
	topologicalSort(adj , n) ;
		
}
