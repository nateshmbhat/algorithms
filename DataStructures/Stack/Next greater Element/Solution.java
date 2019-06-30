import java.util.* ; 
import java.text.* ; 


class Solution{

    public static void main(String[] args){
        Scanner scan = new Scanner(System.in)  ;  

        int [] arr = {4 ,2, 5 , 1 , 0 , 3 , 6 , 10} ; 
        nextGreater(arr);

    }

    public static void print(Object s){
        System.out.println(s.toString()) ; 
    }

    public static void nextGreater(int[] arr)
    {
        Stack<Integer> stk  = new Stack<>(); 

        stk.push(arr[0]) ; 
        int i =1 ; 

        for(i=1 ; i< arr.length ; i++){
            while(!stk.empty() && stk.peek()<=arr[i])
                print(stk.pop() + " -> " + arr[i]) ; 

            stk.push(arr[i]) ; 
        }
        print(stk.pop() + " -> "  + -1) ; 
    }
}