#include<bits/stdc++.h>
using namespace std; 

class myStack {
    public : 
    queue<int> Q ; 
    queue<int> Q_temp ; 

    void push(int ele) ; 
    void printStack() ; 
    int pop(void) ; 
}; 

void myStack::push(int ele){
    Q.push(ele) ; 
}


int myStack::pop(){
    int ele ; 
    if(Q.size()==0 && Q_temp.size()==0)
        cout<<"\nError No elements to pop !" <<endl; 

    else{
            while(Q.size()>1) { 
                Q_temp.push(Q.front()) ; Q.pop() ; 
            }

            ele = Q.front() ; 
            Q.pop() ; 

            while(!Q_temp.empty()) { 
                Q.push(Q_temp.front()) ; Q_temp.pop() ; 
            }
    }
    return ele ; 
}


void myStack::printStack(){
    queue<int> copy  = Q ; 
    while(!copy.empty()){
        cout<< copy.front() << " "  ; 
        copy.pop() ; 
    }
    cout<<endl;
}


int main(void)
{

    myStack obj = myStack() ; 

    obj.push(10) ; 
    obj.push(12) ; 
    obj.push(13) ; 
    obj.push(80) ; 

    obj.printStack() ; 
    obj.pop() ; 
    obj.printStack() ; 
    obj.pop() ; 
    obj.printStack() ; 
    obj.pop() ; 
    obj.printStack() ;
}