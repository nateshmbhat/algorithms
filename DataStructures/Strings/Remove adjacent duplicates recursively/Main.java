
// https://practice.geeksforgeeks.org/problems/recursively-remove-all-adjacent-duplicates/0

import java.util.*;
import java.lang.*;
import java.io.*;

class Main {

	public static String solveString(String s) {

		StringBuffer buf = new StringBuffer() ; 

		int i =0 ; 
		while(i<s.length()){
			int start = 0 ,end =0; 
						
		}
		
		return "" ; 
	}

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int T = scan.nextInt();
		for (int test = 0; test < T; test++) {

			String s = scan.next();

			System.out.println(solveString(s)) ; 

		}
	}
}





import java.util.*;
import java.lang.*;
import java.io.*;
class GFG
 {
     
     public  static void solve(String r){
         HashMap<String,Integer> map = new HashMap<>() ;
         map.put("X" , 10) ;
         map.put("L",50) ; 
         map.put("C",100) ; 
         map.put("D",500) ; 
         map.put("CD",400) ; 
         map.put("I",1) ; 
        map.put("II",2) ; 
        map.put("III",3) ;
        map.put("V",5) ;
        map.put("IV",4) ; 
        map.put("IX",9) ; 
        map.put("XL",40) ;
        map.put("M",1000) ; 
        map.put("CM",900) ; 
        map.put("V",5000) ; 
        map.put("MV",4000) ; 
        
        int sum = 0; 
        for(int i =0 ; i<r.length()  ; i++ ){
            if(i<r.length()-1){
                String temp = ""+r.charAt(i)+r.charAt(i+1) ; 
                if(map.contains(temp)
                    {
                        sum+=map.get(temp) ;
                        i+=1 ;
                    }
                else { 
                    sum+=map.get(temp.charAt(0)) ; 
                }
            }
            else sum+=map.get(r.charAt(i));
        }
        System.out.println(sum) ;
        
     }
     
	public static void main (String[] args)
	 {
	    Scanner scan = new Scanner(System.in) ;
	    int T = scan.nextInt() ;
	    for(int test=0 ; test<T ; test++){
	        String s = scan.next() ;
	        solve(s) ;
	    }
	 }
}