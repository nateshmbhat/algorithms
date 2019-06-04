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
	        
	        int arr[] = new int[256] ;
	        
	        String s= scan.next() ; 
	        for(int i =0 ;i < s.length() ; i++){
	            arr[(int)s.charAt(i)]++ ; 
	        }
	        
	        for(int i =0 ;i < 256 ; i++)
	            if(arr[i]==1) System.out.print((char)arr[i]) ;
	        System.out.println("") ; 
	    
	    }
	 }
}