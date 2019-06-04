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
	        
	        Integer arr[] = new Integer[N] ; 
            for(int i =0 ;i < N ; i++) arr[i]= scan.nextInt() ; 

            PriorityQueue<Integer> queue = new PriorityQueue<Integer>((x,y)->y-x); 

            for(int i =0 ;i < k ;i++ ){
                queue.add(arr[i]) ; 
            }

            for(int i =0 ;i < N-k ;i++){
				System.out.print(queue.peek()+ " ");
				queue.add(arr[i+k]) ; 
				queue.remove(arr[i]) ; 
			}

			System.out.println(queue.peek()+ " ");
  	    }
	 }
}