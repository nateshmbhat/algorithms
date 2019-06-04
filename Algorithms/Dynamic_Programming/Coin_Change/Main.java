//https://www.geeksforgeeks.org/coin-change-dp-7/ 


public class Main{
    static int dpCalls =0 ; 
    static int nonDpCalls =0 ; 
    public static int getCoinChange(int[] arr , int i , int total ){
        nonDpCalls++ ; 
        if(total<0)return 0 ; 
        if(total==0)return 1 ; 
        if(i<0 && total>0)return 0 ; 
        return getCoinChange(arr, i-1 ,total ) + getCoinChange(arr, i, total-arr[i]) ; 
    }

    public static int getCoinChangeDp(int[] arr , int total ){
        int[][] mem = new int[arr.length+10][total+10] ; 
        for(int i =0 ;i <= arr.length; i++){
            for(int j =0 ;j <= total ; j++){
                dpCalls+=1 ; 
                if(j==0) mem[i][j] = 1 ;
                else if(i==0 && j!=0)mem[i][j] = 0 ; 
                else {
                    mem[i][j] = mem[i-1][j]+(j>=arr[i-1]?mem[i][j-arr[i-1]]:0) ; 
                }
            }
        }
        return mem[arr.length][total] ; 
    }
    
    
    public static void main(String[] args) {
        int total = 4 ;
        int arr[] = {1,2,3} ; 
        System.out.println("\nResult = " + getCoinChange(arr , arr.length-1, total)+ " calls = " + nonDpCalls);
        System.out.println("\nResultDP = " + getCoinChangeDp(arr , total) + " calls = " + dpCalls);
    }
}