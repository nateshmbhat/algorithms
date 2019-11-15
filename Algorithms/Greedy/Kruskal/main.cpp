#include<bits/stdc++.h>
#define MAX 100
using namespace std ;
int E ; 

typedef struct {
	int u , v , cost ; 
} Edge ; 

int find(int parent[] , int v){
	while(v!=parent[v])
		v=parent[v] ; 
	return v ; 
}

void takeUnion(int parent[] , int u , int v){
	parent[find(parent, v )] = find(parent , u) ; 
}


void kruskal(Edge edges[]){
	int *parent = new int[MAX] ; //max 100 vertices
	for(int i =0 ;i < MAX ; i++) parent[i]=i ; 
	for(int i =0 ; i<E ; i++){
		Edge current = edges[i] ; 
		if(find(parent , current.u) != find(parent , current.v )){
			cout<<"Edge : " << current.u << " " << current.v<<"  , cost = " << current.cost <<endl; //display edge
			takeUnion(parent,current.u , current.v) ; 
		}
	}
}


int main(void){
	cout<<"Enter number of edges : " ; cin>> E ;
	int u , v , cost ; Edge edges[MAX]  ; // Declarations
	cout<<"Enter edge data in format = u v cost : \n" ; 
	for(int i =0 ;i < E ; i++){
		{
			cin>> u >>v >> cost ; 
			edges[i] = {u , v , cost} ; 
		}
	}
	sort(edges , edges + E, [](Edge a, Edge b){return a.cost < b.cost ;} ); 
	cout<<"Spanning tree is : " <<endl; 
	kruskal(edges) ; 
}