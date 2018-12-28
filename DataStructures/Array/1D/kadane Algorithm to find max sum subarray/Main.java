import java.util.*;
import java.lang.*;
import java.io.*;
class Main
 {
     
    static void sum(int[] arr){
        int max_so_far =0 ,  max_here = 0 ;
		int arrMin = arr[0] ; 
        for(int i=0 ;i < arr.length ; i++){
			arrMin = Math.max(arrMin , arr[i])  ;
            max_here+=arr[i] ; 
            max_here = Math.max(max_here , 0) ;
            max_so_far = Math.max(max_here , max_so_far) ;
		}
		
		if(max_so_far==0)
			max_so_far = arrMin ; 
		System.out.println(max_so_far) ; 
	}
    
	public static void main (String[] args)
	 {
		System.exit(1) ;
	    Scanner scan = new Scanner(System.in) ;
	    int T = scan.nextInt() ;
	    
	    for(int test =0 ; test < T ;test++){
	    int N = scan.nextInt() ;
	    
	    int[] arr = new int[N] ;
	    for(int i =0 ;i < N ; i++){
	        arr[i] = scan.nextInt() ; 
	    }
	    sum(arr); 
	    }
	 }
}