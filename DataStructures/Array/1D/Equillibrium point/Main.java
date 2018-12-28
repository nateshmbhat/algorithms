import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int T = scan.nextInt();
		testcase: for (int t = 0; t < T; t++) {

			int left = 0, right = 0;
			int N = scan.nextInt();
			int[] arr = new int[N];
			for (int i = 0; i < N; i++) {
				arr[i] = scan.nextInt();
				right += arr[i];
			}

			right -= arr[0];

			for (int i = 0; i < N; i++) {
				if (left == right) {
					System.out.println((i + 1));
					continue testcase;
				}
				left += arr[i];
				if (i + 1 < N)
					right -= arr[i + 1];
			}

		}

	}
}