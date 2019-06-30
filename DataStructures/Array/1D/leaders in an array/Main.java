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
	        int arr[] = new int[N] ; 
	        for(int i =0 ;i < N ; i++) arr[i]= scan.nextInt() ; 
	        int max= Integer.MIN_VALUE ; 
	        ArrayList<Integer> list = new ArrayList<>() ; 
	        
	        for(int i=N-1 ;i>=0 ;i--){
	            if(arr[i]>=max){
	                list.add(arr[i]) ;
	                max = arr[i] ;
	            }
	        }
	        Collections.reverse(list) ; 
	        
	        for(Integer i : list){
	            System.out.print(i+ " ") ; 
	        }
	        System.out.println("") ;
	    }
	 }
}