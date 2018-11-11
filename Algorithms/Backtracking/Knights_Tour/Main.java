import java.util.Stack;

import java.util.* ; 

public class Main{
    public static int[][]board  ; 
    public static int[] rowstep , colstep ; 
    public static boolean isFull ;
    static int size = 6 ; 

    public static boolean isSafe(int row , int col ){
        return (row<board.length && row>=0 && col<board.length && col>=0 && board[row][col]==0)  ; 
    }

    public static void  print(){
        for(int i =0 ;i < board.length ; i++){
            for(int j =0 ; j < board.length ; j++){
                System.out.print(board[i][j] + "\t");
            }
            System.out.println("");
        }
        System.out.println("\n\n");
    }


    public static boolean knightTour( int row , int col , int count )
    {
        if(count==(size*size+1))  { 
            return true;
        }

        for(int i =0 ;i < rowstep.length ; i++){

            int nextrow = row+rowstep[i] ; 
            int nextcol= col+colstep[i] ; 

            if(isSafe(nextrow, nextcol)){
                board[nextrow][nextcol] = count ; 
                if(knightTour(nextrow , nextcol , count+1))
                    return true ;
                board[row+rowstep[i]][col+colstep[i]] = 0 ; 
            } 
        }

        return false ; 
    }


    public static void main(String[] args){

        size = 8 ;     
        
        board = new int[size][size] ; 

        rowstep =new int[] {2 , 1 , -1  , -2 , -2 , -1 , 1 , 2 } ; 
        colstep = new int[]{1 , 2 , 2 ,  1 , -1 , -2 , -2 ,  -1 } ;
        
        board[0][0]=1 ; 

        if(knightTour(0 , 0 , 2))
            print() ; 
    }
}