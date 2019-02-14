import java.util.*;
import java.lang.*;
import java.io.*;

class Main
 {
	public static void main (String[] args)
	 {
	    Scanner scan = new Scanner(System.in) ;
	    int T = scan.nextInt() ;
	    for(int test=0 ; test<T ; test++){
	        
	        int N  = scan.nextInt() ; 
	        int k = scan.nextInt() ; 
	        int arr[] = new int[N] ; 
	        for(int i =0 ;i < N ; i++) arr[i]= scan.nextInt() ; 
	        int j =0  , h = j+k-1 ;
	        int i = 0 ;
	        
	        while(i*k<N-1 ){
	            j = i*k ;
	            h= j+k -1 ;
	            if(h>=N)h = N-1 ;  
	            
	            while(j<h){
	                int temp = arr[j] ; 
	                arr[j] = arr[h]  ;
	                arr[h] = temp ;
	                j++ ; h-- ;
	            }
	            i++;
	        }
	        
	        StringBuffer b = new StringBuffer() ; 
	        
	        for(int g=0 ;g< N ; g++){
	            b.append(arr[g]+" ") ; 
	        }
	        System.out.println(b) ; 
	    }
	 }
}