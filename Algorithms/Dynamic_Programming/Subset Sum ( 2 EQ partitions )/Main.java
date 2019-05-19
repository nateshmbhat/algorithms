import java.util.*;
import java.lang.*;
import java.io.*;

class Main
{
     
    public static HashMap<String, Boolean> mem ; 
     
    public static boolean solve(int [] arr , int lsum ,  int rsum , int i ){
        
        if(lsum==rsum){
            System.out.println("YES") ;
            return true ; 
        }
        
        String key = ""+lsum+"-"+rsum+"-"+i ;
        if(mem.containsKey(key)){
            return mem.get(key) ;
        }
        
        if(i>=arr.length) return false ;
        
        if(lsum<rsum){
            mem.put(key , solve(arr , lsum + arr[i] , rsum-arr[i] , i+1) 
            || solve(arr , lsum , rsum , i+1)) ;
        }
        
        return false ;
    }
    
	public static void main (String[] args)
	 {
	    Scanner scan = new Scanner(System.in) ;
	    int T = scan.nextInt() ;
	    for(int test=0 ; test<T ; test++){
	        
	        int N  = scan.nextInt() ; 
	        int arr[] = new int[N] ;
	        mem = new HashMap<String , Boolean>() ;
	        
	        int sum = 0 ; 
	        for(int i =0 ;i < N ; i++) { 
	            arr[i]= scan.nextInt() ; 
	            sum+=arr[i] ; 
	        }
	        mem.clear() ; 
	        if(solve(arr , 0 , sum , 0 )){
	            System.out.println("NO") ;
	        }
	    }
	 }
}