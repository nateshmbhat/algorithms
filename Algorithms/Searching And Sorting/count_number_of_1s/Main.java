// https://www.geeksforgeeks.org/count-1s-sorted-binary-array/
import java.util.* ; 

public class Main{

    public static int countOnesUtil(int[] arr ,  int l , int r )
    {
        if(l==r)return arr[l] ; 
        if(arr[l]==1 && arr[r]==1)return r-l+1 ; 
        if(arr[l]==0 && arr[r]==0)return 0 ; 
        int mid = (l+r)/2 ; 
        return countOnesUtil(arr , l ,mid)+ countOnesUtil(arr,mid+1 , r) ; 
    }

    public static int countOnes(int [] arr){
        return countOnesUtil(arr , 0,arr.length-1 ) ; 
    }

    public static void main(String[] args) {
       int [] arr = new int[]{0,0,0,1,1,1};  
       Scanner scan =new Scanner(System.in) ;
        System.out.println("1s = " + countOnes(arr) );
    }
}