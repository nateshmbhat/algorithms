
import java.util.* ; 

public class Main{

    public static void assignCodes(Vertex root , String temp ){
        // takes the root of huffman tree as input and asssigns the codes 
        if(root.left==null && root.right==null){
            root.code = temp ; 
        }
        if(root.left!=null){
            assignCodes(root.left, temp+"0");
        }
        if(root.right!=null){
            assignCodes(root.right, temp+"1");
        }
    }
    

    public static void huffman(HashMap<Character,Integer> hashMap){
        ArrayList<Vertex> vertexList = new ArrayList<>() ;
        for(Character c : hashMap.keySet()){
            vertexList.add(new Vertex(hashMap.get(c) , ""+c )) ; 
        }

        PriorityQueue<Vertex> pQueue = new PriorityQueue<>(vertexList) ; 
        int counter =1 ; 

        while(pQueue.size()>1){
            Vertex v1 = pQueue.remove() ; 
            Vertex v2 = pQueue.remove() ; 
            pQueue.add(new Vertex(v1.freq+v2.freq , "v"+counter++ , v1 , v2 )) ; 
        }

        assignCodes(pQueue.peek(),"") ; 
        for(Vertex v : vertexList){
            System.out.println(""+ v.c + "  =  " + v.code);
        }
    }

    public static void main(String[] args) { 
        String s ;
        System.out.println("Enter message string : " ); Scanner scan = new Scanner(System.in) ; 

        HashMap<Character,Integer> hashMap = new HashMap<>() ; 
        hashMap.put('a' , 5) ; 
        hashMap.put('b' , 9) ; 
        hashMap.put('c' , 12) ; 
        hashMap.put('d' , 13) ; 
        hashMap.put('e' , 16) ; 
        hashMap.put('f' , 45) ; 

        huffman(hashMap) ; 
    }
}



class Vertex implements Comparable<Vertex>{
    int freq  ; String c ; 
    Vertex left, right ; 
    String code =null ; 

    Vertex(int f , String ch , Vertex v1 ,Vertex v2){
        freq   =f ; c = ch ;
        left = v1  ; right = v2 ; 
    }

    Vertex(int f , String ch ){
        freq   =f ; c = ch ;
        left = right = null ; 
    }

    public int compareTo(Vertex v){
        if(freq<v.freq)return -1 ; 
        if(freq>v.freq)return 1 ; 
        return 0 ;
    }
}