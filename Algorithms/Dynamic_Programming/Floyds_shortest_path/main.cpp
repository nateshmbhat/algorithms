#include<bits/stdc++.h>
using namespace std ; 

void display(vector<vector<int> > D){
	for(int i = 0 ; i < D.size() ; i++){
		for(int j =0 ; j < D[i].size() ; j++){
			cout<< D[i][j] <<" " ; 
		}
		cout<<endl; 
	}
}


void findShortestPath(vector<vector<int> > D){
	for(int k =0 ; k < D.size() ; k++){
		for(int i = 0 ; i < D.size() ; i++){
			for(int j =0 ; j < D[i].size() ; j++){
				D[i][j] = min(D[i][j] , D[i][k]+D[k][j]) ; 
			}
		}
		// display(D) ; cout<<endl<<endl; 
	}

	cout<<"\n\nShortest Path matrix is : " <<endl; 
	display(D) ; 
}


int main(void){

	vector<vector<int> > D  = vector< vector<int> >() ; 
	int n ; cout<<"Enter number of verticies : " ; cin>>n ; 
	cout<<"Enter the weight matrix (9999 indicates infinity) : " <<endl; 
	int temp ; 

	for(int i =0 ;i < n ; i++){
		vector<int> row = vector<int>( ); 
		for(int j = 0 ; j < n ; j++){
			cin>>temp ; 
			row.push_back(temp) ; 
		}
		D.push_back(row) ; 
	}
	findShortestPath(D) ; 
}