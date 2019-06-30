import java.util.* ; 
import java.math.*;

class Main{
    public static void checkIfNumCanBeXPowerY(int n ){
        for(int i =2 ;i <= Math.sqrt(n) ; i++)
        {
            if(n%i==0){
                if(checkHelper(n/i , i )) ;
                    System.out.println("Possible with i = " + i) ;
            }
        }
    }

    public static boolean checkHelper(int n , int factor){
        if(n==1)return true ;
        if(n%factor!=0) return false ; 
        return checkHelper(n/factor , factor) ; 
    }

    public static void main(String[] args) {
        int n = 2187 ;         
        checkIfNumCanBeXPowerY(n) ; 
    }
}