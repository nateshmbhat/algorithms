
// https://practice.geeksforgeeks.org/problems/most-frequent-word-in-an-array-of-strings/0
import java.util.*;
import java.lang.*;
import java.io.*;

class Main {

    public static String solve(String[] arr) {
        HashMap<String, Integer> mem = new HashMap<>();
        int max = 1;

        for (int i = 0; i < arr.length; i++) {
            if (mem.containsKey(arr[i])) {
                max = Math.max(mem.get(arr[i]) + 1, max);
                mem.put(arr[i], mem.get(arr[i]) + 1);
            } else
                mem.put(arr[i], 1);
        }

        String s = null;

        for (int i = 0; i < arr.length; i++) {
            if (mem.get(arr[i]) == max) {
                if (s == null)
                    s = arr[i];
                else if (arr[i].charAt(0) < s.charAt(0))
                    s = arr[i];
            }
        }
        return s ; 
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int T = scan.nextInt();
        for (int test = 0; test < T; test++) {

            int N = scan.nextInt();
            scan.nextLine();
            String[] arr = scan.nextLine().split(" ");

            System.out.println(solve(arr));
        }
    }
}