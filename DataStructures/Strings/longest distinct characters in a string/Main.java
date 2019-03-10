import java.util.*  ;
import java.lang.*  ;
import java.io.*    ;

class Main
 {
     public static boolean check(String s){
        HashSet<Character> set = new HashSet<>() ; 
        for(int i = 0 ;i < s.length() ; i++){
            if(set.contains(s.charAt(i))) return false ; 
            set.add(s.charAt(i)) ;
		}
		return true ; 
     }

	public static void main (String[] args)
	 {
	    Scanner scan = new Scanner(System.in) ;
	    int T = scan.nextInt() ;
	    for(int test=0 ; test<T ; test++){
	        
	        String s = scan.next() ;
	        int arr[] = new int[256] ; 
	        
	        int maxtotal = 0 ;
	        for(int i =1 ; i <= s.length() ; i++)
	        {
	            for(int j =0  ; j < s.length() ; j++)
	            {	
					if(j+i>=s.length()) break; 
	                if(check(s.substring(j,j+i))){
						maxtotal  =Math.max(maxtotal , i) ; 
					}
	            }
			}

			System.out.println(maxtotal) ; 
	    }
	 }
}