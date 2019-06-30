import java.util.*;
import java.lang.*;
import java.io.*;
class Main
 {
     
    public static int solve(int[] arr , int l , int h){
        if(h-l==2) return arr[l]*arr[l+1]*arr[h] ;
        
        return Math.min(
            arr[l] * solve(arr , l+1 , h) , 
            
            solve(arr , l , h-1) * arr[h]
            
            ); 
    }
    
	public static void main (String[] args)
	 {
	    Scanner scan = new Scanner(System.in) ;
	    int T = scan.nextInt() ;
	    for(int test=0 ; test<T ; test++){
	        int N  = scan.nextInt() ; 
	        int arr[] = new int[N] ; 
	        for(int i =0 ;i < N ; i++) arr[i]= scan.nextInt() ; 
	        
	        int res = solve(arr , 0 , N-1) ; 
	        System.out.println(res) ; 
	    }
	 }
}