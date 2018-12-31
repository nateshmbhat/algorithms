import java.util.* ;

class Main{

    static boolean isItSafe(int [][] board , int val , int row , int col ){
        // Returns false if the row , col already has a fixed value or if val is a fixed one in any row or column
        // ASSUMING N x N board
        if(board[row][col]<0) return false ; 
        for(int i =0 ;i < board.length ; i++)
            if(board[row][i]==val || board[row][i]==-val || board[i][col]==val || board[i][col]==-val) return false ; 
        return true; 
    }

    static boolean isItFixed(int [][] board , int val , int row)
    {
        for(int i =0 ;i < board.length ; i++){
            if(val == -board[row][i])    
                return true ; 
        }
        return false ; 
    }

    static boolean solveSudoku(int [][] board , int row , int col){
        if(row>=board.length) {
            for(int i =0 ;i < board.length ; i++){
                for(int j =0 ; j<board.length ; j++){
                    System.out.print(board[i][j]+ "\t") ;
                }
                System.out.println("") ; 
            }
            return true ; 
        }

        if(col>=board.length){
            return solveSudoku(board, row+1 , 0 ) ; 
        }

        if(board[row][col]<0)return solveSudoku(board, row, col+1) ; 

       for(int n=1 ; n<=board.length ; n++){
           if(isItFixed(board, n, row))
                continue ; 
            if(isItSafe(board , n , row , col )){
                board[row][col] = n ; 
                if(solveSudoku(board , row , col+1))
                    return true ;
                board[row][col] = 0 ; 
            }
       } 
       return false ;
    }

 
    public static void main(String[] args) {
        int size = 9 ; 
        int [][] board = new int[size][size] ; 

        // Negative imples fixed values
        board[0][0] = -3 ;
        board[1][2] = -1 ; 
        board[2][1] = -1 ; 
        board[1][3] = -4 ; 

        solveSudoku(board , 0 , 0 )   ;
    }
}