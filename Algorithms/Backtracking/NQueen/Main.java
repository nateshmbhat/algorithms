import java.util.* ;

public class Main{

    static int size = 8 ; 
    static int[][] board = new int[size][size] ;

    public static boolean isSafe(int row , int col){
        for(int i =0 ; i < size ; i++){
            if(board[row][i]!=0 || board[i][col]!=0)return false ; 
        }        

        // top left
        for(int i = row-1 , j =col-1 ; i>=0&& j>=0 ; j--, i--){
            if(board[i][j]!=0)return false ; 
        } 

        // top right
        for(int i =row-1 , j = col+1 ; i>=0 && j<size ; i--, j++ )
        {
            if(board[i][j]!=0)return false ; 
        }
        return true ; 
    }



    public static boolean NQueen(int row )
    {
        if(row>=size)return true ; 

        for(int i = 0 ; i < size ;i ++){
            if(isSafe(row , i ))
            {
                board[row][i] = 1 ; 
                if(NQueen(row+1))
                    return true ; 
                board[row][i]= 0 ; 
            }
        }                
        return false ; 
    }


    public static void print(){
        for(int i =0 ;  i < board.length ; i++){
            for(int j = 0 ;j  < board.length ; j++)
                System.out.print(board[i][j]+"\t") ; 
            System.out.println("");
        }
        System.out.println("\n");
    }

    public static void main(String[] args) {
        board = new int[size][size] ; 
        if(NQueen(0))
            print() ; 
    }
}