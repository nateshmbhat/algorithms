
// https://www.geeksforgeeks.org/subset-sum-problem-dp-25/

import java.util.*;
import java.lang.*;
import java.io.*;

class Main {

    static int totalsum;
    static HashMap<String,Boolean> mem ; 

    static boolean solve(int[] arr, int cursum, int i) {
        if ((totalsum-cursum) == cursum)
            return true;

        if (cursum > totalsum || i >= arr.length)
            return false;

        String key = ""+i + "-"+ cursum ; 
        
        if(mem.containsKey(key)){
            return mem.get(key) ; 
        }
        
        Boolean res = solve(arr, cursum + arr[i], i + 1) || solve(arr, cursum, i + 1) ; 
        mem.put(key , res) ; 
        return res ; 
    }


    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int T = scan.nextInt();
        for (int test = 0; test < T; test++) {

            int N = scan.nextInt();
            int arr[] = new int[N];
            totalsum = 0;
            for (int i = 0; i < N; i++) {
                arr[i] = scan.nextInt();
                totalsum += arr[i];
            }
            mem = new HashMap<String , Boolean>() ; 

            if (solve(arr, 0, 0))
                System.out.println("YES");
            else
                System.out.println("NO");
        }
    }
}