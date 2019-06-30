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
	         
	        int M = scan.nextInt() ; 
	        
	        int N  = scan.nextInt() ;
	        
	        int arr[][] = new int[M][N] ;
	        for(int i =0 ;i < M ; i++){
	            for(int j = 0 ; j < N ; j++){
	                arr[i][j] = scan.nextInt() ; 
	            }
	        }
	        
	        int l = 0 , r = N-1 , b = M-1 , t = 0 ; 
	        while(l<=r && t<=b){
	            for(int i=l ; i<=r ; i++){
	                System.out.print(arr[t][i]+" ")  ;
	            }
	            t++ ;
	            
	            for(int i=t ; i<=b ; i++){
	                System.out.print(arr[i][r]+" ")  ;
	            }
	            r-- ;
	            
	            for(int i=r ; i>=l ; i--){
	                System.out.print(arr[b][i]+" ")  ;
	            }
	            b-- ; 
	            
	            
	            for(int i=b ; i>=t ; i--){
	                System.out.print(arr[i][l]+" ")  ;
	            }
	            l++ ;
	        }
	    }
	 }
}