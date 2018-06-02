// https://www.geeksforgeeks.org/minimum-length-unsorted-subarray-sorting-which-makes-the-complete-array-sorted/

// Examples:
// 1) If the input array is [10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60], your program should be able to find that the subarray lies between the indexes 3 and 8.

// 2) If the input array is [0, 1, 15, 25, 6, 7, 30, 40, 50], your program should be able to find that the subarray lies between the indexes 2 and 5


#include<bits/stdc++.h>

using namespace std ; 

int main(void)
{
    int a[] = {0, 1, 15, 25, 6, 7, 30, 40, 50} ; 
    int n = 9 ; 
    int l =0 , r =0; 

    for(int i =0 , j= n-1  ; i<n-1 ;j-- ,  i++)
    {
        if(a[i]>a[i+1] && !l)
            l = i ;
        if(a[j]<a[j-1] && !r)
            r = j ; 
    }


    int min=a[l] , max = a[r] ;
    for(int i = l ; i<=r ; i++)
    {
       if(a[i]<min) min = a[i] ; 
       if(a[i]>max) max = a[i] ;
    }

    int l_index  =0 , r_index= 0 ; 
    for(int i =0 ;  ; i++)
    {
        if(min<a[i]) l_index = i ;
        if(max>a[i]) r_index = i ; 
    }

    cout<<l_index <<" : "<<r_index ;

}