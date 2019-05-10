import java.util.*;

public class Main{

    public static int longestCommonString(String s1 , String s2 , int i , int j , boolean isMatching ){
        if(i<0 || j<0)
            return 0 ;  
        if(s1.charAt(i)==s2.charAt(j)){
            return 1+ longestCommonString(s1, s2, i-1, j-1 , true) ; 
        }
        if(isMatching) return 0 ; 
        return Math.max(longestCommonString(s1, s2, i-1, j, false) , longestCommonString(s1, s2, i, j-1, false)) ; 
    }

    public static int longestCommonStringDP(String s1 , String s2)
    {
        int n = s1.length() , m = s2.length() ; 
        int [][]mem = new int[n+1][m+1] ; 
        for(int i =0 ;i <=n ; i++){
            for(int j =0 ;j <=m ; j++){
                if(i==0||j==0) mem[i][j] = 0 ; 
                else if(s1.charAt(i-1)==s2.charAt(j-1)){
                    mem[i][j] =1+mem[i-1][j-1] ; 
                    if(i-2>=0 && j-2>=0 && s1.charAt(i-2)!=s2.charAt(j-2))
                        mem[i][j]-=1 ; 
                }
                else mem[i][j] = Math.max(mem[i-1][j], mem[i][j-1]) ; 
            }
        }
        return mem[n][m] ; 
    }

    public static void main(String[] args) {

        String s1 , s2 ; 
        Scanner scan = new Scanner(System.in) ;  
        s1 =scan.next() ; 
        s2 =scan.next() ;

        int res =longestCommonString(s1 , s2 , s1.length()-1 , s2.length()-1 , false)  ;
        System.out.println("Result = " + res + " \n DP result = "+ longestCommonStringDP(s1, s2) );
    }
}