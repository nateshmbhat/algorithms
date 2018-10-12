import java.util.* ; 

class Main{
    static int LCS(String s1 , String s2 , int i , int j  ){
        // NON DP
        if(i==s1.length() || j==s2.length())return 0 ; 
        if(s1.charAt(i)==s2.charAt(j))
            return Math.max(1+Math.max(LCS(s1 , s2 , i+1 , j+1) , LCS(s1 , s2 , i+1 , j)) , LCS(s1,s2,i,j+1)) ; 
        else return Math.max(LCS(s1,s2,i+1 , j) , LCS(s1,s2,i,j+1)) ; 
    }

    static int LCS(String s1 , String s2 ){
        // DP 
        int [][] mem = new int[s1.length()+1][s2.length()+1] ; 
        mem[0][0] = 0 ; 

        for(int i =1 ; i < mem.length; i++){
            for(int j = 1 ; j < mem[i].length ; j++){
                mem[i][j] = Math.max(mem[i][j-1] , mem[i-1][j]) ; 
                if(s1.charAt(i-1)==s2.charAt(j-1)) mem[i][j]+=1 ; 
            }
        }
        return mem[s1.length()][s2.length()] ; 
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in) ; 
        String s1 = scan.next() ; 
        String s2 = scan.next() ; 
        System.out.println("Result = " + LCS(s1 , s2 ));
    }
}