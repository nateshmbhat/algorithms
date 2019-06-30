#include "utils.h"

using namespace std ; 

Matrix::Matrix(int rows , int cols)
{
    this->row = rows , this->col = cols ; 
    srand(time(NULL)) ; 
    M.resize(rows) ; 

    for(int i =0 ; i<rows ; i++)
    {
        M[i].resize(col) ; 
        std::fill(M[i].begin() , M[i].end() , 0 ) ; 
    }
}


void Matrix::fill(string type  , int start  , int end )
{
    if(type=="sequence")
    {
        int c = start ; 
        for(int i =0 ; i<row ; i++)
            for(int j = 0 ; j< col ; j++)
                this->M[i][j] = c++ ;
    }

    else if (type=="random")
    {
        for(int i =0 ; i<row ; i++)
        {
            for(int j =0 ; j<col ; j++)
            {
                this->M[i][j] = rand()%(end  - start) + start ;
            }
        }
    }

}



std::ostream& operator<<(ostream& out , const Matrix& M)
{
    for(int i =0  ; i<M.row ; i++)
    {
        for(int j =0 ; j<M.col ;j++)
        {
            cout<<M.M[i][j] <<"\t" ; 
        }
        cout<<endl; 
    }
    return out ; 
}
