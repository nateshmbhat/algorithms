// https://www.geeksforgeeks.org/check-reversing-sub-array-make-array-sorted/

import java.util.* ;

public class Main{

    public static void solve(int[] arr){
        int start = 0  ,end=arr.length-1 ; 
       for(int i =1 ;i < arr.length ; i++){
            if(arr[i]<arr[i-1])
            {
                start = i-1 ; 
                while(i<arr.length && arr[i]<arr[i-1]){
                   end = i++ ;  
                }
                break ; 
            }
       } 
       System.out.println("start = " + start+ " end = " + end);
    }
    public static void main(String[] args) {
       Scanner scan =new Scanner(System.in) ;  
       
        int[] arr = new int[]{1,2,5,4,3} ; 
        solve(arr) ; 
    }
}