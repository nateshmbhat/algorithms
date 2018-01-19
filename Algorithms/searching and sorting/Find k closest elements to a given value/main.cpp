// https://www.geeksforgeeks.org/find-k-closest-elements-given-value/
// Input: K = 4, X = 35
// Output: 30 39 42 45
#include<bits/stdc++.h>

using namespace std ; 

int main(void)
{

    int arr[] = {12, 16, 22, 30, 35, 39, 42, 
               45, 48, 50, 53, 55, 56}  ;
    int k = 4 , x = 35;
    int n = sizeof(arr)/sizeof(arr[0]) ; 

    int left ,right  ,i  , mid ,high=n-1 ,  low=0  ;

    while(low<high)
    {
        mid = (high+low)/2 ; 
        
        if(arr[mid]==x || (arr[mid]<x && arr[mid+1]>x))
                break ;

        if(x>arr[mid]) low=mid+1 ; 
        else high=mid-1 ; 
    }

    left = mid ; right = mid+1 ;
    arr[left]==x?(--left):1 ; 

    for(int no_of_ele=0 ; no_of_ele < k ; no_of_ele++)
    {
        if(left>=0 && abs(arr[left]-x)<abs(arr[right]-x))
        {
            cout<<arr[left--]<<" " ; 
        }
        else if(right<n){
            cout<<arr[right++]<<" " ; 
        }

    }


}