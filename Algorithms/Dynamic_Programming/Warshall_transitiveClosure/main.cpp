#include<bits/stdc++.h>

using namespace std ; 

void findTransitiveClosure(vector< vector<int> > D){

	for(int k =0 ; k<D.size() ; k++)
	{
		for(int i=0 ; i < D.size(); i++){
			for(int j =0 ; j < D[i].size() ; j++){
				D[i][j] = D[i][j] || (D[i][k] && D[k][j]) ; 
			}
		}
	}

	cout<<"\n\nTransitive Closure is : " <<endl; 
	for(int i=0 ; i < D.size(); i++){
		for(int j =0 ; j < D[i].size() ; j++){
			cout<<D[i][j]<<" " ; 
		}
		cout<<endl; 
	}
}

int main(void)
{
	vector<vector<int> > D  = vector< vector<int> >() ; 
	int n ; cout<<"Enter number of verticies : " ; cin>>n ; 
	cout<<"Enter the adjacency matrix : " <<endl; 
	int temp ; 

	for(int i =0 ;i < n ; i++){

		vector<int> row = vector<int>( ); 
		for(int j = 0 ; j < n ; j++){
			cin>>temp ; 
			row.push_back(temp) ; 
		}
		D.push_back(row) ; 
	}

	findTransitiveClosure(D) ; 
}
