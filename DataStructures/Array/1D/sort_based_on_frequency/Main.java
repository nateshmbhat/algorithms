import java.util.*;
import java.lang.*;
import java.io.*;

class Counter {
    int value, count;

    Counter(int v, int c) {
        value = v;
        count = c;
    }

    void inc() {
        count++;
    }
}



class Main {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int T = scan.nextInt();
        for (int test = 0; test < T; test++) {

            int N = scan.nextInt();
            int arr[] = new int[N];
            HashMap<Integer, Counter> map = new HashMap<>();

            for (int i = 0; i < N; i++) {
                arr[i] = scan.nextInt();
                if (map.containsKey(arr[i])) {
                    map.get(arr[i]).inc();
                } else
                    map.put(arr[i], new Counter(arr[i], 1));
            }

            SortedSet<Counter> res = new TreeSet(new Comparator<Counter>() {
                public int compare(Counter a, Counter b) {
                    if (a.count == b.count)
                        return a.value - b.value;
                    return b.count - a.count;
                }
            });

            res.addAll(map.values()) ; 
            
            for (Counter i : res) {
                for (int temp = 0; temp < i.count; temp++)
                    System.out.print(i.value + " ");
            }

            System.out.println("");
        }
    }
}