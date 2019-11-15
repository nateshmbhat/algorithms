#include<bits/stdc++.h>
#include<iostream>


using namespace std ;

void DFS(int v , int ** adj , bool *visited , int n)
{
	visited[v] = 1 ;
	
	for(int i=0 ; i<n ; i++)
	{
		if(adj[v][i] && !visited[i])
		{
			DFS(i , adj , visited , n) ;
		}
	}
}



int main(void)
{
	int * * adj  = {0} ; 
	
	int n ; 
	cout<<"Enter the number of vertices : " ; 
	cin>> n ; 
	
	adj = new int*[n] ; 
	bool * visited = new bool[n] ;
	
	for(int i =0 ; i < n ; i++){
		adj[i] = new int[n] ;
		visited[i] = 0 ;	
	}
		
	cout<<"Enter adjancency matrix : " ;
	for(int i = 0 ; i < n ; i++)
		for(int j = 0; j < n ; j++)
			cin>>adj[i][j] ;
	int v;
	cout<<"Enter source vertex : " ;
	cin>> v ; 
	DFS(v-1 , adj , visited , n) ;
	
	for (int k=0; k<n; k++)
{
if(visited[k])
{
cout << "\nVertex " << k+1 << " reachable " << endl;
}
else
{
cout << "\nVertex " << k+1 << " not reachable " << endl;
}
}

		
	
}
