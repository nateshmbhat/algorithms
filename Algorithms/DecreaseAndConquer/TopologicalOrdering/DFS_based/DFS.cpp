#include <bits/stdc++.h>
using namespace std;
int counter=0; 

void topological(int adj[][100], bool visited[], int n , int v , int output[] )
{
    for(int i =0 ;i < n ; i++){
        if(!visited[i] && adj[v][i])
            topological(adj , visited , n , i , output) ;
    }
    visited[v] = true ;
    output[counter++] = v ; 
}


int main(void)
{
    int n;
    int adj[100][100];
    bool visited[100]={0};
    cout << "Enter n : "; cin>>n ; 
    cout<<"Enter adj matrix : " <<endl ;
    for(int i =0 ;i < n ; i++)
        for(int j =0 ; j < n ; j++)
            cin>>adj[i][j] ;

    int output[100] ={0} ;
    for(int i =0 ;i < n ; i++){
        if(!visited[i]) topological(adj , visited , n , i , output ) ; 
    }
    for(int i=n-1 ; i>=0 ;i --)
        cout<< output[i]+1<<" " ;
}