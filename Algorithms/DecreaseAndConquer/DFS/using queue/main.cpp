#include<bits/stdc++.h>
#include<iostream>

using namespace std ;

class myStack{
	public : 
	queue<int> main , aux ; 
	
	void push(int data){
		if(main.empty() && aux.empty())
			main.push(data) ;
		else if (main.empty())
			aux.push(data);
		else main.push(data) ; 
	}

	bool empty(){
		return main.empty() && aux.empty() ; 
	}

	int pop(){
		queue<int> toqueue  , fromqueue ; 
		int data ;
		if(main.empty()) {
			toqueue = main ;fromqueue = aux ; 
		}
		else{
			toqueue = aux ; fromqueue = main ;
		}

		while(fromqueue.size()>1)
		{
			toqueue.push(fromqueue.front()) ; 
			fromqueue.pop() ; 
		}
		data = fromqueue.front() ; fromqueue.pop() ;
		return data ;
	}
};


void DFS(int v , int ** adj , bool *visited , int n)
{
	int top = -1 ; visited[v]= 1 ; 
	myStack stk = myStack() ; 
	stk.push(v) ; 

	while(!stk.empty()){
		top = stk.pop() ; 
		cout<< top << " " ; 
		for(int i =0 ;i  < n ; i++){
			if(adj[top][i] && !visited[i])
			{
				visited[i] = 1 ; 
				stk.push(i) ; 
			}
		}
	}

	cout<<endl; 
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
