import java.util.*;
import java.lang.*;
import java.io.*;

class Main{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int T = scan.nextInt();
        for (int test = 0; test < T; test++) {

            int N = scan.nextInt();
            int M = scan.nextInt();

            int[][] ma = new int[N][M];

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    ma[i][j] = scan.nextInt();
                }
            }

            int[][] mem = new int[N + 1][M + 1];
            int max = 0;

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    if (i == 0 || j == 0)
                        mem[i][j] = ma[i][j];
                    else if (ma[i][j] == 0)
                        mem[i][j] = 0;
                    else
                        mem[i][j] = 1 + Math.min(mem[i - 1][j], Math.min(mem[i][j - 1], mem[i - 1][j - 1]));
                    max = Math.max(mem[i][j], max);
                }
            }

            System.out.println(max);

        }
    }
}