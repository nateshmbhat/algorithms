import java.util.* ;
import java.io.* ; 

class Main{

    static boolean isItSafe(int [][] board, int size , int val , int row , int col ){
        // Returns false if the row , col already has a fixed value or if val is a fixed one in any row or column
        // ASSUMING N x N board
        val = Math.max(val , -val ) ; 
        if(board[row][col]<0) return false ; 
        for(int i =0 ;i < size; i++)
            if(board[row][i]==val || board[i][col]==val ) return false ; 
        
        
        int subcols , subrows , subRowStart , subColStart ; 
    
        if(size!=6){
            subcols = size/3 ; //total cols in a subrow
            subrows = 3 ; //total rows in a subrow 
        }
        else{
            subrows = 2 ; 
            subcols = 3 ; 
        }

        subRowStart = (row/subrows) * (subrows) ; 
        subColStart = (col/subcols) * subcols ; 

        for(int i =subRowStart ;i < (subRowStart+subrows) ; i++)
        {
            for(int j = subColStart ; j< (subColStart+subcols) ; j++){
                if(board[i][j]==val && i!=row && j!=col )
                    return false ; 
            }
        }

        return true; 
    }

    static boolean isItFixed(int [][] board,int size , int val , int row)
    {
        for(int i =0 ;i < size ; i++){
            if(val == -board[row][i])    
                return true ; 
        }
        return false ; 
    }

    static boolean solveSudoku(int [][] board , int size , int row , int col){
        if(row>=size) {
            for(int i =0 ;i < size ; i++){
                for(int j =0 ; j<size ; j++){
                    System.out.print(board[i][j]+ "\t") ;
                }
                System.out.println("") ; 
            }
            return true ; 
        }

        if(col>=size){
            return solveSudoku(board,size, row+1 , 0 ) ; 
        }

        if(board[row][col]<0)return solveSudoku(board,size, row, col+1) ; 

        ArrayList<Integer> numbers = new ArrayList<Integer>() ; 
        for(int i =0 ;i < size ; i++) numbers.add(i+1) ; 

        Collections.shuffle(numbers);

       for(int i=0 ; i<numbers.size(); i++){
           if(isItFixed(board,size, numbers.get(i), row))
                continue ; 
            if(isItSafe(board,size , numbers.get(i) , row , col )){
                board[row][col] = numbers.get(i) ; 
                if(solveSudoku(board, size , row , col+1))
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
        // board[0][0] = -9 ;
        // board[0][1] = -3 ; 
        // board[1][8] = -1 ; 
        // board[2][3] = -9 ; 
        // board[2][4] = -5 ; 
        // board[3][5] = -5 ; 
        // board[5][2] = -5 ; 
        // board[6][8] = -8 ; 
        // board[7][8] = -9 ; 
        // board[7][0] = -5 ; 
        // board[7][3] = -8 ; 
        // board[7][4] = -1 ; 
        // board[8][7] = -8 ; 
        solveSudoku(board, size, 0 , 0 ) ; 
        
    }
}