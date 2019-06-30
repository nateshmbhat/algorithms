// https://practice.geeksforgeeks.org/problems/form-a-palindrome/0
// Incomplete !!!!

import java.util.*;
import java.lang.*;
import java.io.*;
class GFG
 {
	public static void main (String[] args)
	 {
	    Scanner scan = new Scanner(System.in) ;
	    int T = scan.nextInt() ;
	    for(int test=0 ; test<T ; test++){
	        String s = scan.next() ; 
	        System.out.println(solve(s , 0 , s.length()-1)) ; 
	    }
	 }
	 
	 public static int solve(String s , int i , int j ){
	   if(i>=j ) return 0 ;
	   if(s.charAt(i)==s.charAt(j))
	        return solve(s , i+1 , j-1) ;
	   else return Math.min(solve(s , i+1 , j) , solve(s,i,j-1))+1 ; 
     }
     
	 public static int solveDP(String s){
        int mem[][] =new int[s.length()+1][s.length()+1] ; 
        for(int i=1 ; i<=s.length() ; i++){
            for(int j =s.length() ; j > 0 ; j--){
                if(i>=j) mem[i][j] = 0 ; 
                else if(s.charAt(i-1)==s.charAt(j-1))
                    mem[i][j] = mem[i-1][j+1] ; 
                else mem[i][j] = Math.min(mem[i][j-1],mem[i-1][j]) ; 
            }
        }
	   if(i==j || i>j) return 0 ;
	   if(s.charAt(i)==s.charAt(j))
	        return solve(s , i+1 , j-1) ;
	   else return Math.min(solve(s , i+1 , j) , solve(s,i,j-1))+1 ; 
	 }
	
	 
}