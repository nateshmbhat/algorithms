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
			Integer arr[] = new Integer[N] ; 
	        for(int i =0 ;i < N ; i++) arr[i]= scan.nextInt() ;
			int k = scan.nextInt() ;

            PriorityQueue<Integer> q =  new PriorityQueue<>(Arrays.asList(arr)) ;
			for(int i =0 ;i < k-1 ; i++) q.poll() ; 
			System.out.println(q.poll());
	    }
	 }
}