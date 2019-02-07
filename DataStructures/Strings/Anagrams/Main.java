import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int T = scan.nextInt();
		test:
		for (int test = 0; test < T; test++) {

			String s1 = scan.next();
			String s2 = scan.next();

			HashMap<Character, Integer> map = new HashMap<>();

			for (int i = 0; i < s1.length(); i++) {
				Integer c = map.get(s1.charAt(i));
				map.put(s1.charAt(i), c == null ? 1 : (c + 1));
			}

			for (int i = 0; i < s2.length(); i++) {
				Integer c = map.get(s2.charAt(i));
				map.put(s2.charAt(i), c == null ? -1 : (c - 1));
			}

			for (Map.Entry<Character, Integer> e : map.entrySet()) {
				if(e.getValue()!=0){ 
					System.out.println("NO");
					continue test ; 
				}
			}
			System.out.println("YES");
		}
	}
}