#include<bits/stdc++.h>

using namespace std ; 

int V ; 

int minKey(int key[], bool mstSet[]) 
{ 

int min = INT_MAX, min_index; 
  
for (int v = 0; v < V; v++) 
    if (mstSet[v] == false && key[v] < min) 
        min = key[v], min_index = v; 
  
return min_index; 
} 


int printMST(int parent[], int n, int graph[100][100])
{ 
printf("Edge \tWeight\n"); 
for (int i = 1; i < V; i++) 
    printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]); 
} 
  
void primMST(int graph[100][100]) 
{ 
    
    int parent[V];  
    
    int key[V];  
    
    bool mstSet[V];  
  
    
    for (int i = 0; i < V; i++) 
        key[i] = INT_MAX, mstSet[i] = false; 
  
    key[0] = 0;      
    parent[0] = -1; 
  
    for (int count = 0; count < V-1; count++) 
    { 
        
        int u = minKey(key, mstSet); 
        
        mstSet[u] = true; 
       
        for (int v = 0; v < V; v++) 
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) 
                parent[v] = u, key[v] = graph[u][v]; 
    } 
  
    printMST(parent, V, graph); 
} 


int main(void){

    cout<<"Enter number of vertices : " ; 
    cin >> V ; 
    int graph[100][100] ; 
    cout<<"Enter weight matrix : " <<endl; 
    for(int i =0 ;i < V ; i++ )
    {
        for(int j =0 ; j < V ; j++)
            cin>>graph[i][j] ; 
    }
   
    primMST(graph); 
}
