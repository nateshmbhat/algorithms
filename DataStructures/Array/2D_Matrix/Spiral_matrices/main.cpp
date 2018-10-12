#include <bits/stdc++.h>

#include "../utils.h"

using namespace std  ; 


void Matrixspiral(vector<vector<int>> M)
{
    int a[M.size()+2][M[0].size()+2]  ; 
    int shift[][2] = {{1 , 0} , {0 , 1} , {-1 , 0 } , {0 , -1}} ; 
    int dir = 0  , x =0 , y =0 , nextx , nexty ; 

    for(int i =0 ; i< M.size() *M.size() ; i++)
    {
        cout<<M[x][y] << " " ; 
        a[x][y] = M[x][y] ; 
        M[x][y] = 0 ; 

        nextx = x + shift[dir][0] , nexty = y+ shift[dir][1]  ;

        if(nextx>=M[0].size() || nextx<0 || nexty>=M[0].size() || nexty < 0 || a[nextx][nexty]==0 )
        {
            dir = (dir+1)%4 ;
            nextx = x + shift[dir][0] , nexty = y+ shift[dir][1] ; 
        }
        x = nextx  , y = nexty ;
    }
}


int main()
{
    Matrix obj = Matrix(3 , 3) ; 
    obj.fill() ; 
    cout<<obj ; 
    Matrixspiral(obj.M) ; 
}
