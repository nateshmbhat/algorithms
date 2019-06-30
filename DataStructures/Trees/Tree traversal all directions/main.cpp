#include<bits/stdc++.h>
#include"../utils.h"
using namespace std; 


void left_to_right_top_to_bottom(Node * root) 
{
    cout<<"\n\nLeft to right , Top to bottom : " <<endl; 
    // Normal BSF traversal 
    queue<Node * > Q ;  Node * popped ; 
    Q.push(root) ; 

    while(!Q.empty())
    {
        popped = Q.front() ; Q.pop() ; 
        cout<<popped->data  << " " ; 
        if(popped->l) Q.push(popped->l)  ;  
        if(popped->r) Q.push(popped->r)  ;  
    }
    cout<<endl<<endl; 
}


void right_to_left_top_to_bottom(Node * root)
{
    cout<<"\n\nRight to Left , Top to bottom : " <<endl; 
    // Normal BSF traversal 
    queue<Node * > Q ;  Node * popped ; 
    Q.push(root) ; 

    while(!Q.empty())
    {
        popped = Q.front() ; Q.pop() ; 
        cout<<popped->data  << " " ; 
        if(popped->r) Q.push(popped->r)  ;  
        if(popped->l) Q.push(popped->l)  ;  
    }
    cout<<endl<<endl; 
}



void left_to_right_bottom_to_top(Node * root)
{

    cout<<"\n\nLeft to Right , bottom to Top : " <<endl; 
    stack<vector<Node * >  > stk ; vector<Node  * > Q ;
    Q.push_back(root) ; stk.push(Q) ; 

    while(true)
    {
        vector<Node * > newQ  ; 
        vector<Node * > oldQ = stk.top() ; 

        for(int i =0 ; i<oldQ.size() ; i++)
        {
            if(oldQ[i]->l) newQ.push_back(oldQ[i]->l) ; 
            if(oldQ[i]->r) newQ.push_back(oldQ[i]->r) ; 
        }
        if(newQ.size()==0) break ; 
        stk.push(newQ) ; 
    }

    while(!stk.empty())
    {
       Q = stk.top() ; stk.pop() ;  
       for(int i =0 ; i< Q.size() ; i++)
       {
           cout<< Q[i]->data <<" " ; 
       }
    }
    cout<<endl; 
}


void right_to_left_bottom_to_top(Node * root)
{
    cout<<"\n\nRight to Left , bottom to Top : " <<endl; 
    stack<vector<Node * >  > stk ; vector<Node  * > Q ;
    Q.push_back(root) ; stk.push(Q) ; 

    while(true)
    {
        vector<Node * > newQ  ; 
        vector<Node * > oldQ = stk.top() ; 

        for(int i =0 ; i<oldQ.size() ; i++)
        {
            if(oldQ[i]->r) newQ.push_back(oldQ[i]->r) ; 
            if(oldQ[i]->l) newQ.push_back(oldQ[i]->l) ; 
        }
        if(newQ.size()==0) break ; 
        stk.push(newQ) ; 
    }

    while(!stk.empty())
    {
       Q = stk.top() ; stk.pop() ;  
       for(int i =0 ; i< Q.size() ; i++)
       {
           cout<< Q[i]->data <<" " ; 
       }
    }

    cout<<endl; 
}



int main(void)
{
    Tree mytree(50) ;
    vector<int> bsftree = {32 ,21 , 42, 18 , 0 , 0 , 88, 14 , 0 , 78 , 92 , 0 , 0 ,66 , 0 , 0,0,0,73} ;
    // vector<int> bsftree = {50 , 42 , 71 , 27,48,66,99,6,35,42,48,65 , 0,82,0,5, 7,0,0,0,0,0,0,0,0,90,0,1,0,0,13,0,96,0,2,0,25} ; 
    
    // vector<int> bsftree = {6 , 5, 7 , 1 , 0 , 0 , 13 , 0 , 2 , 0 , 25 , 0, 0, 21962} ; 

    Tree tree = mytree.buildCustomTree(bsftree) ; 
    tree.prettyPrint() ;
    left_to_right_top_to_bottom(tree.getRoot()) ;
    right_to_left_top_to_bottom(tree.getRoot()) ; 
    left_to_right_bottom_to_top(tree.getRoot()) ; 
    right_to_left_bottom_to_top(tree.getRoot()) ; 
}