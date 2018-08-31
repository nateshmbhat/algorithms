{
    // INITIAL CODE
    import java.util.*;
    import java.lang.*;
    import java.io.*;
    // A Binary Tree node
    class Node
    {
        int data;
        Node left, right;
        Node(int item)
        {
            data = item;
            left = right = null;
        }
    }
    class Level_Order_Traverse
    {
        
        
        // driver function to test the above functions
        public static void main(String args[])
        {
            
            // Input the number of test cases you want to run
            Scanner sc = new Scanner(System.in);
            int t = sc.nextInt();
            //Node root=null;
            while (t > 0)
            {
                HashMap<Integer, Node> m = new HashMap<Integer, Node> ();
                int n = sc.nextInt();
                Node root=null;
                while (n > 0)
                {
                    int n1 = sc.nextInt();
                    int n2 = sc.nextInt();
                    char lr = sc.next().charAt(0);
                    //  cout << n1 << " " << n2 << " " << (char)lr << endl;
                    Node parent = m.get(n1);
                    if (parent == null)
                    {
                        parent = new Node(n1);
                        m.put(n1, parent);
                        if (root == null)
                            root = parent;
                    }
                    Node child = new Node(n2);
                    if (lr == 'L')
                        parent.left = child;
                    else
                        parent.right = child;
                    m.put(n2, child)
                    n--;
                }
            
                GfG g = new GfG();
                g.levelOrder(root);
                System.out.println();
                t--;
                
            }
        }
    }
    
    }
    
    /*Please note that it's Function problem i.e.
    you need to write your solution in the form of Function(s) only.
    Driver Code to call/invoke your function is mentioned above.*/
    
    class GfG
    {
        void levelOrder(Node node) 
        {
            Queue<Node> queue = new AbstractQueue<Node>() ; 
            
            queue.add(node) ; 

            while(!queue.isEmpty()){
                if(queue.peek().left!=null)
                    queue.add(queue.peek().left) ; 
                
                if(queue.peek().right!=null)
                    queue.add(queue.peek().right) ; 

                System.out.print(queue.remove()+ " ")  ; 
            }
        }
    }