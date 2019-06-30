// https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram/0/?ref=self

import java.util.*;
import java.lang.*;
import java.io.*;
class Main
 {
	//  Less efficient O(N^2) solution  .
	public static void main (String[] args)
	{
	    Scanner scan = new Scanner(System.in) ;
	    int T = scan.nextInt() ;
	    for(int test=0 ; test<T ; test++){
	        
	        int N  = scan.nextInt() ; 
	        int arr[] = new int[N] ; 
	        for(int i =0 ;i < N ; i++) arr[i]= scan.nextInt() ;
	        
	        int max = Integer.MIN_VALUE ;
	        for(int i =0 ;i < N ; i++){
	            int k = arr[i] ; 
	            int j , h ; 
	            for(j = i+1 ; j<N  && arr[j]>=k ; j++);
	            for(h = i-1 ; h>=0  && arr[h]>=k ; h-- , j++);
	            max = Math.max(k*(j-i)  , max) ;
	        }
	        System.out.println(max) ; 
	    }
	}
}