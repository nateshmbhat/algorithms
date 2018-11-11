import java.util.* ;
import java.util.Map.Entry; 


public class Main{
    public static void main(String[] args) {

        String s= "hellothisismynewclassicstring" ; 
        HashMap<Character , Integer> hashMap = new HashMap<>() ; 

        for(char c : s.toCharArray() ){
            if(hashMap.containsKey(c))
                hashMap.put(c , hashMap.get(c)+1) ; 
            else hashMap.put(c , 1) ; 
        }

        ArrayList<Vertex> vertexList = new ArrayList<>() ;
        for(Character key : hashMap.keySet())
        {
            vertexList.add(new Vertex( hashMap.get(key) , key ))  ; 
        }

        PriorityQueue<Vertex> priorityQueue = new PriorityQueue<>(vertexList) ; 
        for(Vertex v : priorityQueue){
            System.out.println("Vertex = " + v);
        }

        while(priorityQueue.size()>1){

        }
    }
}


class Vertex implements Comparable<Vertex>{
    int freq  ;
    char c ; 
    Vertex(int f, char mychar){
       freq = f  ; c =  mychar ;
    }

    public String toString(){
        return "char = " + c + " , freq = "  + freq ; 
    }
    
    public int compareTo(Vertex V){
        if(freq<V.freq)return -1 ; 
        if(freq>V.freq)return 1 ; 
        return 0 ; 
    }
}