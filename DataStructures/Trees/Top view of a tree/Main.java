import java.util.*;
class TreeNode
{
    int key;
    TreeNode left, right;
    public TreeNode(int key)
    {
        this.key = key;
        left = right = null;
    }
}
class Main
{
    public static void main(String[] args)
    {
		Scanner sc=new Scanner(System.in);
		int tc=sc.nextInt();
		while(tc-->0){
			int n=sc.nextInt();
			TreeNode root = null;
			if(n==0){
				System.out.println();
				continue;
			}
			for(int i=0;i<n;i++){
				int a1=sc.nextInt();
				int a2=sc.nextInt();
				char ch=sc.next().charAt(0);
				if(root==null){
					root=new TreeNode(a1);
					switch(ch){
						case 'L':root.left=new TreeNode(a2);
						break;
						case 'R':root.right=new TreeNode(a2);
						break;
					}
				}
				else{
					insert(root,a1,a2,ch);
				}
			}
			GfG g = new GfG();
			g.printTopView(root);	
			System.out.println();
		}
    }
	public static void insert(TreeNode root,int a1,int a2,char ch){
		if(root==null)
			return;
		if(root.key==a1){
			switch(ch){
						case 'L':root.left=new TreeNode(a2);
						break;
						case 'R':root.right=new TreeNode(a2);
						break;
					}
		}
		else{
			insert(root.left,a1,a2,ch);
			insert(root.right,a1,a2,ch);
		}
	}
}


/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*Complete the function below
Node is as follows
class TreeNode
{
    int key;
    TreeNode left, right;
    public TreeNode(int key)
    {
        this.key = key;
        left = right = null;
    }
}*/
class GfG
{
    static int min = 9999 , max = -9999 ; 
    
    static void printTopView(TreeNode root)
    {
        Queue<TreeNode> que = new LinkedList<>() ; 
        que.add(root) ;
        
        TreeNode node = null ;
        
        while(!que.isEmpty()){
            System.out.print(que.peek().key+" ") ;
            
            int n = que.size() ; 
            for(int i = 0 ; i < n ; i++){
                node = que.poll() ;
                if(node.left !=null ) que.add(node.left) ; 
                if(node.right!=null) que.add(node.right) ;
            }
            if(n!=1){
                System.out.print(node.key+ " ") ; 
            }
        }
    }
}