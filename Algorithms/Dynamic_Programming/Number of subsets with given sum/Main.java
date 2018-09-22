import java.util.* ;
/*
input : 1 2 3 4 5 6 , sum = 10 
output : 5

since 1+2+3+4 = 2+3+5 = 6+4  = 1+4+5 = 6+3+1 10 
4 subsets are there ....

*/

class Main{
    static int calls = 0 ; 
    static int callsNonDp = 0 ; 

    static int helperNonDp(int arr[] , int low , int sum){
        callsNonDp+=1 ;
        if(sum==0)return 1 ; 
        if(low>=arr.length)return 0 ; 
        if(sum<arr[low]) return helperNonDp(arr, low+1, sum) ; 
        else{
            return helperNonDp(arr, low+1, sum-arr[low])+helperNonDp(arr, low+1, sum) ;
        }
    } 

    static int helper(int[]arr , int low , int sum , HashMap<String,Integer> mem){
        calls++;
        int retval  , val1 , val2; 
        if(sum==0){
            return 1; 
        }

        if(low>=arr.length) return  0 ;

        if(sum<arr[low]){  
            if(mem.containsKey(""+low+":"+sum)) 
            {
                retval=mem.get(""+low+":"+sum) ; 
                mem.put(""+low+":"+sum , retval) ; 
            }
            else retval = helper(arr, low+1, sum , mem) ;
        }

        else{
            if(mem.containsKey(""+(low+1)+(sum-arr[low])))
                val1 = mem.get(""+(low+1)+(sum-arr[low])) ; 
            else { 
                val1 = helper(arr, low+1, sum-arr[low] , mem ) ;
                mem.put(""+(low+1)+(sum-arr[low]) , val1) ; 
            }
            
            if(mem.containsKey(""+(low+1)+(sum)))
                val2 =mem.get(""+(low+1)+sum) ; 
            else { 
                val2 = helper(arr, low+1, sum , mem) ; 
                mem.put(""+(low+1)+(sum) , val2) ; 
            }

            retval = val1+val2 ;
        }
        return retval ; 
    }

    static int noSubSets(int arr[] , int sum){
        HashMap<String,Integer> mem = new HashMap<>() ; 
        helperNonDp(arr, 0 , sum) ;
        return helper(arr , 0   , sum , mem);
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in) ; 
        int arr[] = new int[]{1,24,25,26,28,29,30,31,33,37 ,2 ,3, 4 , 5 , 6,13,14,15,18,19 , 7 , 8 , 10 , 11 , 21 , 20 , 23 , 32,27,100} ; 
        int sum = 100 ; 
        int res = noSubSets(arr, sum);
        System.out.println("Calls = " + calls + " Result = " + res + " NON DP = "+callsNonDp);
    }
}