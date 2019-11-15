#include<bits/stdc++.h>
#include<iostream>

using namespace std ;

void BFS(int v , int ** adj , bool *visited , int n)
{
	int front ; 
	queue<int> Q = queue<int>() ; 
	Q.push(v) ; 
	while(!Q.empty()){
		front =  Q.front()  ;Q.pop() ; 
		cout<<front+1<<" " ; 
		visited[front] = 1 ; 
		for(int i =0 ;i  < n ; i++){
			if(adj[front][i] && !visited[i])
			{
				Q.push(i) ; 
			}
		}
	}
	cout<<endl<<endl;  
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
	for(int i = 0 ; i < n ; i++){
			for(int j = 0; j < n ; j++)
				cin>>adj[i][j] ;
	}
	
	int v;
	cout<<"Enter source vertex : " ;
	cin>> v ; 
	
	BFS(v-1 , adj , visited , n) ;
	
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
