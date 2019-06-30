// https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array/
#include<bits/stdc++.h>

using namespace std ; 


void partition(vector<int>& a , int  l , int r )
{
    int pivot = a[0] ; 

    int i = l , j = r ;  
    while(i<j)
    {
        while(a[i]<=pivot) i++ ; 
        while(a[j]>pivot)j-- ; 
        swap(a[i] ,a[j]) ; 
    }
    swap(a[i] , a[j]) ; 
    swap(a[0] , a[j]) ; 

}

int partition_r(vector<int> & a, int l , int r )
{
    int pi =  l + rand()%(r-l)  ;
    swap(a[0] , a[pi]) ;  
    partition(a , l , r) ; 
    return pi ; 
}


int findkthlargest_quickselect(vector<int> a , int l , int r  , int k)
{
    int pindex = partition_r(a , l , r) ; 
    if(l<r)
    {
    if(r-pindex==k)
        return a[r-pindex] ; 
    else if(k<(r-pindex))
        return findkthlargest_quickselect(a , pindex+1 , r , k) ; 
    else
        return findkthlargest_quickselect(a , l , pindex - 1, k) ;
    }
 
}


int findkthlargest_bubblesort(vector<int> a , int k)
{
    for(int i =0 ; i< k ;i++)
    {
        for(int j = 0 ; j<a.size() -1 ; j++ )
        {
            if(a[j]>a[j+1]) swap(a[j] , a[j+1]) ; 
        }
        
    }
    
    return a[a.size()-k] ; 
}


int main()
{
    srand(time(NULL)) ; 
    vector<int> a = {7, 10, 4, 3, 20, 15} ; 
    partition_point(a.begin() , a.end() , 2) ; 
    for(int i : a){
        cout<<i<< " " ; 
    }
    cout<<endl; 
    int k = 4 ; 
    cout<< "ans = " <<findkthlargest_quickselect(a  , 0 , a.size()-1 , k ) <<endl; 
    cout<<"ans = "<< findkthlargest_bubblesort(a , k ) <<endl; 
}