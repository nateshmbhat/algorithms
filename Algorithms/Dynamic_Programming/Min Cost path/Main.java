import java.util.*;

class Main {

    static int x, y; // Destination
    static int DPCalls = 0, NonDPCalls = 0, BottomUp = 0;

    public static int findMinCost(int[][] weights, int m, int n) {

    }

    public static int findMinCost_DP(int[][] weights, int m  , int n , int[][] mem )
    {
        DPCalls+=1 ;
        if(m==x && n == y)return weights[m][n] ; 

        if(m>=weights.length || n>=weights[m].length)return 0 ; 
        if(mem[m][n]>0)return mem[m][n] ; 

        int result =weights[m][n] +  Math.min(Math.min(findMinCost_DP(weights , m+1 , n ,mem) , findMinCost_DP(weights, m , n+1 , mem)), findMinCost_DP(weights , m+1 , n+1 , mem )) ; 
        mem[m][n] = result   ; 
    
    
        return result ; 
    }

    public static int findMinCost_DP_BottomUp(int[][] weights, int m, int n) {

        int[][] mem = new int[m + 1][n + 1];
        mem[0][0] = weights[0][0];
        for (int i = 1; i <= m; i++)
            mem[i][0] = mem[i - 1][0] + weights[i][0];
        for (int i = 1; i <= n; i++)
            mem[0][i] = mem[0][i - 1] + weights[0][i];

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                BottomUp += 1;
                mem[i][j] = weights[i][j] + Math.min(Math.min(mem[i - 1][j], mem[i][j - 1]), mem[i - 1][j - 1]);
            }
        }

        return mem[m][n];
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        em.out.println("Enter order m and n : ");
        int m = scan.nextInt();
        int n = scan.nextInt();  
          
        System.out.println("Enter Destination x and y : ");
        x = scan.nextInt();
        y = scan.nextInt(); 
        int[][] matrix = newi
        for (int i = 0; i < m; i++)  
            for (int j = 0; j < n; j++)  
                matrix[i][j] = scan.nextInt();

        int[][] mem = new int[m][n];
        System.out.println("Min cost = " + 
        System.out.println("Min  cos t =  "  + ( matrix [0] [0]  +f id MinCst_P(ma tri x,  0,  0,  me)))
                   
        System.out.println("Min cost = " + (fin
        System.out.println("\nDp calls = "  + DPCalls + "  Non DP = " + NonDPCalls + " Bottom Up = " + BottomUp); ; 
    }
}