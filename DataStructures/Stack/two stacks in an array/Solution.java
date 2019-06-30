import java.util.* ; 
import java.text.* ; 


class Solution{

    static int [] arr  ; 

    static int n = 10 ; 
    static int top1 =-1 , top2 = n ;

    public static void main(String[] args){
        arr =  new int[10] ; 
        Scanner scan = new Scanner(System.in)  ;  

        for(int i = 0 ;i < 6  ; i++){
            pushLeft(i); 
        }

        for(int i = 0 ;i < 6  ; i++){
            pushRight(i); 
        }

        for(int i = 0 ;i < 3  ; i++){
            popLeft(); 
        }

        printStack(arr, 0 , top1) ; 
        printStack(arr, top2 , n-1) ; 
    }

    public static void pushLeft(int a){
        if(top2-top1>1) 
        {top1+=1 ; arr[top1] = a ; }
        else println("\nOverflow") ;

    }

    public static void pushRight(int a){
        if(top2-top1>1) 
        {top2-=1 ; arr[top2] = a ; }
        else println("\nOverflow") ;
    }

    public static int popLeft(){
        if(top1<0) { println("\nnot possible") ;  return -1 ; } 
        else{
            return arr[top1--] ; 
        }
    }

    public static int popRight(){
        if(top2>=n) { println("\nnot possible") ;  return -1 ; } 
        else{
            return arr[top2++] ; 
        }
    }


    public static void printStack(int[] arr , int beg , int end)
    {
        for(int i = beg ; i <=end ; i++) print(arr[i] + " ") ; 
        println("");
    }

    public static void print(Object s){
        System.out.print(s.toString()) ; 
    }
    public static void println(Object s){
        System.out.println(s.toString()) ; 
    }

}