import java.util.* ; 

class Main{

    static final int MAXFLAG = 9999 ;

    public static Integer getMinimumSteps(int [][] arr , int row , int col){
        if(row>=arr.length || col>=arr[row].length || arr[row][col]==1 ) return MAXFLAG ; 
        if(row==arr.length-1 && col==arr[row].length-1) return 0 ; 
        
        int right = getMinimumSteps(arr , row , col+1) ; 
        int down = getMinimumSteps(arr, row+1 , col) ; 
        
        return Math.min(right , down)+1 ; 
    }

    public static Integer getMinimumStepsDP(int [][] arr , int row , int col, Map<String,Integer> mem ){
        
        if(row>=arr.length || col>=arr[row].length || arr[row][col]==1 ) return MAXFLAG ; 
        if(row==arr.length-1 && col==arr[row].length-1) return 0 ; 

        String key = ""+row+"-"+col ; 
        if(mem.containsKey(key)) return mem.get(key) ; 
        
        int right = getMinimumSteps(arr , row , col+1) ; 
        int down = getMinimumSteps(arr, row+1 , col) ; 
        
        mem.put(key , Math.min(right , down)+1 ) ; 
        return mem.get(key) ; 
    }



    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in) ; 
        Integer T = scan.nextInt() ; 
        
        
        for(int t=0 ; t<T ; t++){
            int m = scan.nextInt() ; 
            int n = scan.nextInt() ; 
            
            int arr[][] = new int[m][n] ; 

            for(int i =0 ; i < m ;i++)
                for(int j = 0 ; j< n ; j++)
                    arr[i][j] = scan.nextInt() ; 
            
            Map<String,Integer> mem = new HashMap<>() ; 
            int result = getMinimumStepsDP(arr,0,0 , mem ) ; 
            if(result>=MAXFLAG) System.out.println("NO");
            else 
                System.out.println(result ) ; 
        }
    }
}