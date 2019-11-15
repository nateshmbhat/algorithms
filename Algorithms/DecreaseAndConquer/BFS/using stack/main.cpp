#include<bits/stdc++.h>
#include<iostream>

using namespace std ;

class Stack{
    public : 
    int top ;int a[100] ; 
    int aux[100] ; 
    int topaux  ;
    Stack(){top =-1 ;topaux =-1 ; }
    void enqueue(int data ){a[++top] = data ; }
    int dequeue(){
        if(top<0)return -1; 
        while(!empty())aux[++topaux] = a[top--] ; 
        int data= aux[topaux--] ; 
        while(topaux>=0)a[++top] = aux[topaux--] ; 
        return data;
    }
    int front(){
        if(top<0)return -1 ; 
        return a[0]  ;
    } 
    bool empty(){return top<0  ; }
}; 


void BFS(int v , int ** adj , bool *visited , int n)
{
	int front ; 
    Stack Q = Stack() ; 
	Q.enqueue(v) ; 
	while(!Q.empty()){
		front =  Q.front()  ;Q.dequeue() ; 
		cout<<front+1<<" " ; 
		visited[front] = 1 ; 
		for(int i =0 ;i  < n ; i++){
			if(adj[front][i] && !visited[i])
			{
				Q.enqueue(i) ; 
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
