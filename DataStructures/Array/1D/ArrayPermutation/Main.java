import java.util.*  ; 

class Main{
    public static void permute(ArrayList<Integer> arr , int s){

        if(s==arr.size()){
            System.out.println(arr);
        }

        for(int i = s  ; i < arr.size() ;i++ )
        {
            Collections.swap(arr , s , i) ; 
            permute(arr, s+1);
            Collections.swap(arr , s , i) ; 
       }
    }



    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in) ;         
        ArrayList<Integer> arr = new ArrayList<>() ;
        for(String s : scan.nextLine().split(" ")){
            arr.add(Integer.parseInt(s)) ; 
        }

        permute(arr, 0);
   }
}