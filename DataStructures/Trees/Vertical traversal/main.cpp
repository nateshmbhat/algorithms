#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
void verticalOrder(Node *root);
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct Node* newNode(int data)
{
  struct Node* node = (struct Node*)
                       malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  scanf("%d ", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d ",&n);
     struct Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = newNode(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = newNode(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     verticalOrder(root);
     cout << endl;
  }
  return 0;
}


/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
void verticalOrder(Node *root)
{
    int minval = INT_MAX , maxval = INT_MIN ; 
    queue<Node * > q ; 
    queue<int> hd ; 
    q.push(root) ; 
    hd.push(0) ; 
    vector<Node * >  myzerovec; 
    unordered_map< int , vector<Node *> >  mymap ; 

    while(!q.empty()){
        Node * cur = q.front() ; q.pop() ; 
        int curHd = hd.front() ; hd.pop() ; 

        minval = min(minval , curHd) ; 
        maxval = max(maxval , curHd) ; 

        if(mymap.find(curHd)==mymap.end()){//not found in hash
          vector<Node *> myvec ;
          myvec.push_back(cur) ; 
          mymap[curHd] = myvec ; 
        }
        else{
            mymap[curHd].push_back(cur) ; 
        }
        if(cur->left) {
          q.push(cur->left) ; 
          hd.push(curHd-1) ; 
        }
        if(cur->right) {
          q.push(cur->right) ; 
          hd.push(curHd+1) ; 
        }
    }

    for(int i = minval ; i <= maxval ; i++){
      vector<Node * > myvec = mymap[i] ;
      for(Node * j : myvec){
        cout<< j->data << " " ; 
      }
    }
    cout<<endl; 
}