import java.util.*;
import java.lang.*;
import java.io.*;
class Main
 {
	public static void main (String[] args)
	 {
	    Scanner scan = new Scanner(System.in) ;
	    int T = scan.nextInt() ;
	    for(int t =0 ; t< T ; t++){
	        int  N = scan.nextInt()  , max = Integer.MIN_VALUE ,maxindex = 0 ;
	        int arr[] = new int[N] ; 
	        int mem[]= new int[N] ; 
	        for(int i =0 ;i < N ; i++) {
	            arr[i] = scan.nextInt() ; 
	            mem[i] = arr[i] ; 
	        }
	        
	        for(int i =1 ; i < N ; i++){
	            max = Integer.MIN_VALUE  ; 
	            maxindex = 0 ; 
	            
	            for(int j =0 ; j<i ; j++){
	                if(arr[j]<arr[i] && mem[j]>max){
	                    maxindex = j ;
	                    max = mem[j] ;
	                }
	            }
	            
	            mem[i] = Math.max(mem[i] , mem[i]+max) ;
	        }
	
	        max = Integer.MIN_VALUE ;         
	        for(int i =0  ; i < N ;i++){
	            max = Math.max(max , mem[i]) ; 
	        }
	        
	        System.out.println(max)  ;
	        
	    }
	 }
}