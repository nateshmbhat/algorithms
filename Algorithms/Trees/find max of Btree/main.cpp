#include<bits/stdc++.h>
#include<list>
// #include "../trees.h"

using namespace std ; 

int partition(int * arr , int l , int h )
{
    
}

void sort(int arr[] , int l , int h)
{
    if(l==h) return ; 
    int pivot = partition(arr , l , h) ; 
    
}


int main(void)
{
    srand(time(NULL)) ; 
    int a[100] ; 

    for (int i =0 ; i< 100 ; i++) 
        a[i] = rand()%200 ; 
    
    sort(a , 0 , 99) ; 



    // Tree temp(150) ; 
    // Tree myt = temp.generateRandBST(10) ;

    // cout<<myt ; 

    // cout<<"\n" <<myt.findMax(myt.root) ; 
    // cout<<endl<<myt.isBST(myt.root) ; 
    // cout<<myt ; 
}