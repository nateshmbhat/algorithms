import java.util.* ; 

class Main{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in) ;
        String s= scan.nextLine().trim().replace(" " , "") ; 
        Tree tree = new Tree(s) ; 
        System.out.println("Inorder traversal is : "); tree.inorder();
    }
}

class Tree {
    String data ;
    Tree left , right ; 

    public void inorder(){
        if(left!=null)left.inorder();
        System.out.print(data+ " ");
        if(right!=null)right.inorder();
    }

    private int getPreced(char c){
        switch(c){
            case '=' : return 0 ; 
            case '+' : return 1 ; 
            case '-' : return 1 ; 
            case '*' : return 2 ; 
            case '/' : return 2 ; 
            case '^' : return 3 ; 
            default : return -1 ; 
        }
    }

    Tree(String s){
        String ops = "=+-*/^" ;
        for(int op = 0 ; op< ops.length() ; op++)
        {
            for(int i =0 ;i < s.length() ; i++ ){
                if(getPreced(ops.charAt(op))==getPreced(s.charAt(i)))
                {
                    left = new Tree(s.substring(0 , i )) ; 
                    right = new Tree(s.substring(i+1,s.length())) ; 
                    this.data = ""+s.charAt(i) ; 
                    return ;
                }
            }
        }
        data = s ; 
    }
}