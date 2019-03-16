import java.util.* ; 
import java.lang.* ;

class Item{
    int v , w ; 
    Item(int v , int w){
        this.v = v ; this.w = w ; 
    }
}

public class Solution{
    static int[][] values  ;  
    static int nocalls =0 ; 
    public static int knapsack(Item[] items , int c){
        return knapsack_driver(items, 0 , 0 , c ) ; 
    }

    public static void main(String[] args) {
        

        values = new int[100][100] ;
        Item[] arr = new Item[5] ; 
        arr[0] = (new Item(5 , 1 )) ; 
        arr[1 ] = (new Item(3 , 2 )) ; 
        arr[2] = (new Item(5 , 4 )) ; 
        arr[3] = (new Item(3 , 2 )) ; 
        arr[4] = (new Item(2 , 5 )) ; 
        int c= 10 ; 

        System.out.println("Result = " + knapsack( arr , c ));
        System.out.println("nocalls = " +nocalls) ; 
        nocalls =0 ; 
        System.out.println("Result DP = " + knapsack_driver_DP( arr , 0 ,  c ));
        System.out.println("nocalls = " +nocalls) ; 

    }


    private static int knapsack_driver_DP(Item[] items , int p, int cap){
        nocalls++ ;
        if(values[p][cap]>0) return values[p][cap] ; 
        int res = 0 ;

        if(p>=items.length || cap==0) { return 0 ; }

        if(cap<items[p].w) { 
            res =  knapsack_driver_DP(items, p+1 , cap) ;
        }

        else{
            res = Math.max(knapsack_driver_DP(items, p+1 , cap-items[p].w) , knapsack_driver_DP(items, p+1, cap)) ; 
        }

        return values[p][cap] ; 
    }
    

    private static int knapsack_driver(Item[] items , int p,int value , int cap){
        nocalls++ ;
        if(p>=items.length)return value ; 
        if(cap<items[p].w) return knapsack_driver(items, p+1 , value, cap) ; 
        else{
            int yes = knapsack_driver(items, p+1 , value+items[p].v , cap-items[p].w) ;
            int no = knapsack_driver(items, p+1 , value, cap) ; 
            return Math.max(yes ,no) ; 
        }
    }
}

