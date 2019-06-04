import java.util.* ; 

class Main{
    static int nonDp = 0 ; 
    static int Dp = 0 ; 
    public static void main(String[] args) {
        int[] arr = {10, 22, 9, 33, 21, 50, 41, 60, 80} ; 
        // int[] arr ={3, 10, 2, 1, 20}  ; 
        // int[] arr ={50, 3, 10, 7, 40, 80} ; 
        LIS(arr) ; 
    }

    public static void LIS(int [] arr){
        System.out.println( LISHelperNonDp(arr, 0 , Integer.MIN_VALUE )+" calls = " + nonDp) ;
        HashMap<String,Integer> mem = new HashMap<>() ; 
        System.out.println( LISHelperDp(arr, 0 , Integer.MIN_VALUE , mem )+ " calls = " + Dp ) ;
        System.out.println( LISHelperBottomUpDp(arr)) ; 
    }

    public static int LISHelperNonDp(int[] arr , int i , int cur){
        nonDp+=1 ; 
        if(i>=arr.length)return 0 ; 
        if(arr[i]>cur) return Math.max(1+LISHelperNonDp(arr, i+1, arr[i]), LISHelperNonDp(arr, i+1, cur)) ; 
        else return LISHelperNonDp(arr, i+1, cur) ;
    }


    public static int LISHelperDp(int[] arr , int i , int cur , HashMap<String,Integer> mem){
        Dp+=1 ;
        if(mem.containsKey(""+i+'-'+cur)) return mem.get(""+i+'-'+cur) ; 
        if(i>=arr.length)return 0 ; 
        int res1=Integer.MIN_VALUE , res2 ; 
        if(arr[i]>cur) {
            res1 = 1+LISHelperDp(arr, i+1, arr[i] , mem ) ; 
            res2 =  LISHelperDp(arr, i+1, cur , mem) ; 
        }
        else { 
            res2 = LISHelperDp(arr, i+1 , cur , mem) ;
        }
        mem.put(""+i+"-"+cur, Math.max(res1,res2)) ; 
        return Math.max(res1,res2) ; 
    }

    public static int LISHelperBottomUpDp(int[] arr){
        int [] list = new int[arr.length] ; 

        for(int i =0 ;i < arr.length ; i++){
            list[i] = 1 ;  
            for(int j =0 ;j < i ; j++){
                if(list[i] < list[j]+1  &&  arr[i]>arr[j])
                    list[i] = list[j]+1 ; 
            }
        }
        int max = Integer.MIN_VALUE ; 
        for(int i =0 ;i < list.length ; i++){
            max = Math.max(list[i] , max) ; 
        }
        return max ; 
    }
}