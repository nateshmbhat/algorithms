import java.util.*;
import java.lang.*;
import java.io.*;
class Main
 {
	public static void main (String[] args)
	 {
	    Scanner scan = new Scanner(System.in) ;
		int T = scan.nextInt() ;
		scan.nextLine() ;
	    for(int test=0 ; test<T ; test++){
			String line = scan.nextLine() ; 
            String [] words = line.split("\\.") ;
            for(int i=words.length-1 ; i>0 ;i--)
                System.out.print(words[i]+".") ; 
			System.out.println(words[0]) ;
	    }
	 }
}