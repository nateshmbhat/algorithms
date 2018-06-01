#include<bits/stdc++.h>

using namespace std ; 


class BinaryTree{

    typedef struct node{
        int data ; 
        struct node * l ;
        struct node * r  ; 
    } node; 

    public:
    node * root; 
    int size ; 
    
    BinaryTree()
    {
        root = 0 ;
        size = 0 ; 
    }

    void fnAddNode(int  ) ; 
    bool fnDelNodeKey(int ) ; 
    void fnTraInOrder(node * ) ; 
    void fnTraPreOrder(node * ) ; 
    void fnTraPostOrder(node * ) ; 

};



void BinaryTree::fnAddNode(int data) 
{
    node * newnode = new node ;
    newnode->l = newnode->r = 0  ; 
    newnode->data = data ; 

    if(!root){
        this->size++ ; 
        this->root = newnode ; 
        return ;
    }

    node * temp = root ; 
    node * parent = root ;

    while(temp)
    {
        parent = temp ; 
        if(data<temp->data)
            temp = temp->l ; 
        else
            temp= temp->r ; 
    }

    if(data>parent->data)
        parent->r = newnode ; 
    else
        parent->l = newnode ; 
    
    this->size++ ; 
}



bool BinaryTree::fnDelNodeKey(int key)
{
    //RETURNS true if successfully deleted , else false 
    if(!root)return 0; 

    node * cur = root , *parent=0 ; 
    node * q; 

    while(cur)
    {
        if(key==cur->data)
            break ; 
        parent = cur ;
        if(key<cur->data)
            cur = cur->l ; 
        else
            cur = cur->r ; 
    }

    if(cur==NULL) return false ; 
    if(cur->l==NULL)
        q = cur->r ; 
    else if(cur->r ==NULL)
        q = cur->l ; 

    else{

        q = cur->r  ; 
        node * temp = q ; 
        while(temp->l!=NULL)
            temp = temp->l ; 

        temp->l = cur->l ; 
    }

    if(parent==NULL) // KEY IS at ROOT
    {
        delete cur ; 
        root = q; 
        return 1; 
    }
    
    if(parent->l==cur)
        parent->l = q ; 
    else
        parent->r = q ; 
    
    return 1 ; 

}


void BinaryTree::fnTraInOrder(node * root)
{
    if(root==NULL) return ; 
    fnTraInOrder(root->l);
    cout<<root->data <<" " ; 
    fnTraInOrder(root->r) ; 
}

void BinaryTree::fnTraPreOrder(node * root)
{
    if(root==NULL) return ; 
    cout<<root->data <<" " ; 
    fnTraPreOrder(root->l);
    fnTraPreOrder(root->r) ;

}

void BinaryTree::fnTraPostOrder(node * root )
{
    if(root==NULL) return ; 
    fnTraPostOrder(root->l);
    fnTraPostOrder(root->r) ;
    cout<<root->data <<" " ; 
}



int main(void)
{

    BinaryTree T ; 
    int num , ch  ; 
    
    while(1)
    {
        cout<<"\n\n1.Add node\t2.Delete key\t3.Display\t4.Exit : " ; 
        cin>>ch ; 
        switch(ch)
        {
            case 1:
                cout<<"Enter number : " ; 
                cin>>num ;
                T.fnAddNode(num) ; 
                break ; 

            case 2:
                cout<<"Enter key to delete : " ; 
                cin>>num ; 
                T.fnDelNodeKey(num) ;                 
                break ; 


            case 3:
                cout<<"Size : " <<T.size <<endl;
                cout<<"InOrder : " ; 
                T.fnTraInOrder(T.root) ; 
                cout<<endl ;
                cout<<"PreOrder : "; 
                T.fnTraPreOrder(T.root) ; 
                cout<<endl; 
                cout<<"PostOrder : "; 
                T.fnTraPostOrder(T.root) ; 
                cout<<endl; 
                break; 
            
            case 4:
                exit(0) ;
        }

    }


}