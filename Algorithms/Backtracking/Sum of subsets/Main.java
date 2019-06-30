//Print all subsets of a set which form a given sum 

import java.util.*;

public class Main{

    public static void sumOfSubsets(int[] arr , int sum){
        sumOfSubsetsUtil(arr, new Stack<Integer>() , 0 , sum );
    }


    public static void sumOfSubsetsUtil(int[] arr , Stack<Integer> stk , int i ,  int sum )
    {
        if(sum==0){
            System.out.println(stk);
            return ; 
        }

        if(i>=arr.length)return ; 
         
        sumOfSubsetsUtil(arr, stk , i+1 , sum );
        stk.push(arr[i]) ; 
        sumOfSubsetsUtil(arr, stk, i+1, sum-arr[i]);
        stk.pop() ; 
    }


    public static void main(String[] args) {
        int n  ; 
        System.out.println("Enter n : " ); Scanner scan = new Scanner(System.in) ; 
        n = scan.nextInt() ;  
        int[] arr = new int[n] ; 
        System.out.println("Enter elements : ");
        for(int i =0 ;i < n ; i++){
            arr[i] = scan.nextInt() ;             
        }

        System.out.println("Enter sum : ");
        sumOfSubsets(arr , scan.nextInt()) ; 
    }

}