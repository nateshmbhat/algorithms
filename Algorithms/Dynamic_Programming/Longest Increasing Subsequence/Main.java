import java.util.* ; 

class Main{

    public static void LIS(int [] arr){
        System.out.println("normal : "+LISutil(arr , arr.length-1 , arr.length-1)) ; 
    }

    public static int LISutil(int[] arr , int i , int lastIncluded){
        if(i<0)return 0 ;
        if(arr[i]<=arr[lastIncluded])
           return Math.max(1+LISutil(arr , i-1 , i ) , LISutil(arr, i-1, lastIncluded)) ;
        return LISutil(arr, i-1, lastIncluded) ; 
    }

    public static int LISutilDP(int[] arr ){
        int[][] mem = new int[100][100] ; 
        for(int i =0 ;i <= arr.length ; i++){
            for(int j = 0;j <=arr.length ; j++){
                if(i==0)mem[i][j] =0 ; 
                else {
                    mem[i][j] = Math.max(1+mem[i-1][i] , mem[i-1][j]) ; 
                }
            }
        }
        return 1 ; 
    }
    
    public static void main(String[] args) {
        int[] arr = new int[]{10, 22, 9, 33, 21, 50, 41, 60, 80}; 
        LIS(arr) ; 
    }
}