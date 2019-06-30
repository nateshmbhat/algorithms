#include<bits/stdc++.h>
using namespace std; 

class Edge{
    public : 
    int src , dest , weight ;     
    Edge(int a , int b ):src(a) , dest(b){weight = 1 ; }
};

unordered_map<int , int > parent  ; 

int find(int i)
{
    if(parent[i]<0) return i ; 
    else return find(parent[i]) ; 
}

void Union(int x , int y )
{
    int findx = find(x) ; 
    int findy = find(y) ; 

    int parx = parent[findx] ; 
    int pary = parent[findy] ; 

    if(parx<pary){
        parent[findx] = parx+pary ; 
        parent[findy] = findx ; 
    }
    else { 
        parent[findy] = parx+pary ; 
        parent[findx] = findy ; 
    }
}


void MinimumSpanningTree(vector<int> vert  , vector<Edge> edges) 
{
    for(Edge edge : edges)
    {
        if(find(edge.src) == find(edge.dest))
        {
            cout<< " cycle at : " << edge.src << " --- " << edge.dest <<endl; 
        }
        else{
            Union(edge.src , edge.dest) ; 
        }
    }            
}


int main(void)
{
    vector<Edge> edges ;
    vector<int> vertices ; 

    for(int i = 0 ; i< 5 ; i++) vertices.push_back(i) ; 
    for(int i =0 ;i < 5 ; i++) parent[i] = (-1) ; 
    edges.push_back(Edge(0 , 4)) ; 
    edges.push_back(Edge(0 , 2)) ; 
    edges.push_back(Edge(2 , 1)) ; 
    edges.push_back(Edge(1 , 3)) ; 
    edges.push_back(Edge(2 , 3)) ; 

    MinimumSpanningTree(vertices , edges) ; 
}