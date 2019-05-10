import java.util.*;
import java.lang.*;
import java.io.*;
class Main
 {
    
    static void swap(char[] s , int i , int j){
        char temp = s[i] ; 
        s[i] = s[j] ; 
        s[j] = temp ; 
    }
     
    static void  perm(char[] s , int start){
        if(start==s.length-1){
            System.out.print(new String(s)+ " ") ;
            return ; 
        }
        
        for(int i = start ;i < s.length ; i++){
            swap(s , start , i ) ;
            perm(s , start+1) ;
            swap(s , start , i) ;
        }
    }
     
	public static void main (String[] args)
	 {
	    Scanner scan = new Scanner(System.in) ;
	    int T = scan.nextInt() ;
	    for(int test=0 ; test<T ; test++){
	        
	        char[] s = scan.next().toCharArray() ;
	        perm(s ,  0) ; 
	        System.out.println("") ; 
	    }
	 }
}