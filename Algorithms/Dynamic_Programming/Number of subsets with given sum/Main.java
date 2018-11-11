import java.util.* ;
/*
input : 1 2 3 4 5 6 , sum = 10 
output : 5

since 1+2+3+4 = 2+3+5 = 6+4  = 1+4+5 = 6+3+1 10 
5 subsets are there ....

*/

class Main{
    static int calls = 0 ; 
    static int callsNonDp = 0 ; 
    static int callsBottomUpDp= 0 ; 

    static int helperNonDp(int[] arr ,int sum , int i){
        callsNonDp+=1 ; 
        if(sum==0)return 1 ;
        if(i<0 || sum <0 )return 0 ; 
        return helperNonDp(arr, sum-arr[i], i-1) + helperNonDp(arr, sum, i-1) ; 
    }

    static int helperDp(int[] arr ,int sum , int i , HashMap<String,Integer> mem){
        calls+=1 ; int r1=0 , r2 ; 
        if(mem.containsKey(""+i+"-"+sum)) return mem.get(""+i+"-"+sum); 
        if(sum==0)return 1 ;
        if(i<0 || sum<0)return 0 ; 
        r1 = helperDp(arr, sum-arr[i], i-1 , mem) ;
        r2 = helperDp(arr, sum, i-1 , mem ) ; 
        mem.put(""+i+"-"+sum , (r1+r2)) ; 
        return r1+r2 ; 
    }

    static int bottomUpDp(int[] arr , int sum){
        int[][] mem = new int[arr.length+1][sum+1] ; 
        mem[0][0]= 1 ; 
        int i , j ; 

        for(i=1; i<mem.length ; i++){
            for(j=0 ; j<=sum ; j++){
                callsBottomUpDp+=1;
                if(arr[i-1]>j) mem[i][j] = mem[i-1][j] ; 
                else mem[i][j] = mem[i-1][j] + mem[i-1][j-arr[i-1]] ; 
            }
        }
        System.out.println("\nResult is : " + mem[i-1][sum]) ; 
        return mem[arr.length-1][sum] ; 
    }

    static int noSubSets(int[] arr , int sum){
        bottomUpDp(arr, sum) ; 
        helperDp(arr, sum, arr.length-1, new HashMap<>()) ;
        return helperNonDp(arr, sum, arr.length-1) ; 
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in) ; 
        int arr[] = new int[]{1,24,25,26,28,29,30,31,33,37 ,2 ,3, 4 , 5 , 6,13,14,15,18,19 , 7 , 8 , 10 , 11 , 21 , 20 , 23 , 32,27,100} ; 
        // int arr[] = new int[]{1,2,3,4,5,6} ; 
        // int arr[] = new int[]{1,2,7,5} ; 
        int sum = 100 ; 
        int res = noSubSets(arr, sum);
        System.out.println("TopDownDPCalls = " + calls + " Result = " + res + " NON DP = "+callsNonDp + " BottomUpDpCalls = " + callsBottomUpDp);
    }
}