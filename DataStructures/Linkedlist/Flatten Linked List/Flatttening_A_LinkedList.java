import java.util.Scanner;
import java.util.*;
import java.io.*;
class Node
{
    int data;
    Node next;
    Node bottom;
    
    Node(int d)
    {
        data = d;
        next = null;
        bottom = null;
    }
}
class Flatttening_A_LinkedList
{	
    Node head;
    
    void printList(Node node)
    {
        //Node temp = head;
        while (node != null)
        {
            System.out.print(node.data + " ");
            node =node.bottom;
        }
        System.out.println();
    }
    public  static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        Flatttening_A_LinkedList list = new Flatttening_A_LinkedList();
        while(t>0)
        {
            int N = sc.nextInt();
            int arr[] = new int[N];
            for(int i=0;i<N;i++)
                arr[i] = sc.nextInt();
            
            Node temp = null;
            Node tempB = null;
            Node pre = null;
            Node preB = null;	
            int flag=1;
            int flag1=1;
            for(int i=0; i<N;i++)
            {
                int m = arr[i];
                m--;
                int a1 = sc.nextInt();
                temp = new Node(a1);
                if(flag == 1)
                {
                    list.head = temp;
                    pre = temp;
                    flag = 0;
                    flag1 = 1;
                }
                else
                {
                    pre.next = temp;
                    pre = temp;
                    flag1 = 1;
                }
                
                for(int j=0;j<m;j++)
                {
                    int a = sc.nextInt();
                    tempB = new Node(a);
                    if(flag1 == 1)
                    {
                        temp.bottom = tempB;
                        preB = tempB;
                        flag1 = 0;
                    }
                    else
                    {
                        preB.bottom = tempB;
                        preB = tempB;
                    }
                }
                
            }
            //list.printList();
            GfG g = new GfG();
            Node root = g.flatten(list.head);
            list.printList(root);
        
        t--;
        }
    }	
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*Node class  used in the program
class Node
{
    int data;
    Node next;
    Node bottom;
    
    Node(int d)
    {
        data = d;
        next = null;
        bottom = null;
    }
}
*/
/*  Function which returns the  root of 
    the flattened linked list. */
class GfG
{
    Node flatten(Node root)
    {
        if(root.next==null) return root ;
        Node res = mergeLists(root , root.next) ;
        res.next = root.next.next ;
        return flatten(res) ;
    }
    
    Node mergeLists(Node A , Node B){
        Node temp ; 
        if(B==null) return A ;
        
        if(B.data<A.data){
            temp = B ;
            B = B.bottom ;
        }
        else{
            temp = A ; 
            A = A.bottom ;
        }
        Node start = temp ;
        
        while(A!=null && B!=null){
            if(A.data< B.data){
                temp.bottom = A ;
                A = A.bottom ;
            }
            else{
                temp.bottom = B ; 
                B = B.bottom ;
            }
            temp = temp.bottom ;
        }
        
        if(A!=null) temp.bottom = A;
        if(B!=null) temp.bottom = B;
        
        return start ; 
    }
}