

#include<bits/stdc++.h>

#ifndef MatrixUtils 
#define MatrixUtils

using namespace std ; 

class Matrix{
    public:
    std::vector<vector<int>> M ; 
    int row , col ; 


    Matrix(int row , int col) ;
    void fill(string type = "sequence" , int start = 1 , int end = 100) ; 
    friend std::ostream& operator<<(std::ostream& , const Matrix& ) ; 
};

#endif