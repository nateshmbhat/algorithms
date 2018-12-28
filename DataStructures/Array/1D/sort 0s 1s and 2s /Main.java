import java.util.*;
import java.lang.*;
import java.io.*;
class Main
 {
     
     static void swap(int[] arr, int a , int b ){
         int temp = arr[a] ; 
         arr[a] = arr[b] ;
         arr[b] = temp ; 
     }
     
	public static void main (String[] args)
	 {
	    Scanner scan = new Scanner(System.in) ;
	    int T = scan.nextInt() ;
	    for(int t= 0 ; t< T ; t++){
	        int N = scan.nextInt() ; 
	        
	        int arr[] = new int[N] ; 
	        for(int v=0;v < N ; v++) arr[v] = scan.nextInt() ;
	        
	        int k = 1, i=0 , j = N-1 ;
	        
			while(k<=j){
				switch(arr[k]){
					case 2:
						swap(arr, j-- , k++) ; break ;
					case 0:
						swap(arr , i++ , k++) ; break ; 
					case 1 :
						k++ ; 
				}
			}
	       
	       for(int v=0 ; v< N ; v++)
	        System.out.print(arr[i]) ; 
	       System.out.println("") ;
	    }
	 }
}