import java.util.*;
import java.lang.*;
import java.io.*;
class Main
 {
	public static void main (String[] args)
	 {
	    Scanner scan = new Scanner(System.in) ;
	    int T = scan.nextInt() ;
	    
	    testcase:
	    for(int test=0 ; test<T ; test++){
	        
	        int N  = scan.nextInt() ; 
	        int arr[] = new int[N] ; 
	        HashSet<Integer> set = new HashSet<>() ; 
	        for(int i =0 ;i < N ; i++) set.add(scan.nextInt()) ;
	        
	        for(int i=1 ; i<1000 ; i++){
				if(!set.contains(i)) continue ;
	            for(int j =i+1 ; j<=1000 ; j++){
					if(!set.contains(j)) continue ;
	                double t = Math.sqrt(i*i + j*j) ;
					double u = Math.sqrt(j*j - i*i) ;
					int tfloor = (int)t   ;
					int ufloor = (int)u ; 

	                if(t==tfloor && set.contains(tfloor))
	                    {
							System.out.println("Yes") ;
							continue testcase ; 
						}
						
					if(u==ufloor && set.contains(ufloor))
	                    {
							System.out.println("Yes") ;
							continue testcase ; 
	                    }

	            }
	        }
	        System.out.println("No") ;
	        
	        
	    }
	 }
}