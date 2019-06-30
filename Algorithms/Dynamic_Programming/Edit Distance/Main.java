import java.util.* ;

class Main{
    static int nonDP = 0 , DP = 0 ; 
    static int smallest_edit_distance(String s1 , String s2 , int m , int n ){
        nonDP+=1 ; 
        if(m==0)return n ; 
        if(n==0 )return m ; 
        else{
            if(s1.charAt(m)==s2.charAt(n)) return smallest_edit_distance(s1, s2, m-1, n-1) ; 
            else{
                return 1+ Math.min(Math.min(smallest_edit_distance(s1, s2, m-1, n) , smallest_edit_distance(s1, s2, m, n-1)) , smallest_edit_distance(s1, s2, m-1, n-1)); 
            }
        }
    }

    static int smallest_edit_distance_DP(String s1 , String s2 , int m , int n , int mem[][])
    {
        DP+= 1; 
        int res = 0 ; 

        if(mem[m][n]>0)return mem[m][n] ;
        if(m==0)return n ; 
        if(n==0 )return m ; 

        if(s1.charAt(m)==s2.charAt(n)) res = smallest_edit_distance_DP(s1, s2, m-1, n-1 , mem) ; 
        else{
            res = 1+ Math.min(Math.min(smallest_edit_distance_DP(s1, s2, m-1, n , mem) , smallest_edit_distance_DP(s1, s2, m, n-1 , mem)) , smallest_edit_distance_DP(s1, s2, m-1, n-1 , mem)); 
        }

        mem[m][n] = res ; 
        return res ; 
    }


    static int smallest_edit_distance_DP_bottom_up(String s1 , String s2 )
    {
        int [][] mem= new int[s1.length()+1][s2.length()+1] ; 

        for(int i =0 ;i <= s1.length(); i++){
            for(int j = 0 ;j <= s2.length() ; j++){
                if(i==0) mem[i][j] = j ; 
                else if(j==0)mem[i][j] = i ; 
                else if(s1.charAt(i-1) == s2.charAt(j-1))   mem[i][j] = mem[i-1][j-1] ; 
                else mem[i][j] = 1 + Math.min( mem[i][j-1] , Math.min(mem[i-1][j-1] , mem[i-1][j])) ; 
            }
        }

        return  mem[s1.length()][s2.length()] ;
    }



    public static void main(String[] args) {
        String s1, s2 ; 
        Scanner scan = new Scanner(System.in) ;      
        s1 = scan.next() ; s2= scan.next() ; 
        int mem[][]= new int[s1.length()] [s2.length()] ; 
        System.out.println("Result = " + smallest_edit_distance(s1, s2, s1.length()-1, s2.length()-1) ) ; 
        System.out.println("Result = " + smallest_edit_distance_DP(s1, s2, s1.length()-1, s2.length()-1 , mem)); 
        System.out.println("Result = " + smallest_edit_distance_DP_bottom_up(s1, s2)); 
        System.out.println("NonDP = " + nonDP +  " DP = " + DP) ; 
    }
}