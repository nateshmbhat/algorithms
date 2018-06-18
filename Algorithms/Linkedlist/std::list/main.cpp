#include<bits/stdc++.h>
#include<list>
using namespace std; 

int main(void)
{
    list<int> L ; 
    forward_list<int> fL; 
    L.push_back(10) ; 
    L.push_back(12) ; 

    L.empty() ; 
    L.pop_back() ;
    L.empty() ; 
    L.pop_back() ; 

    for(int c  : L)
    {
        cout<<c<<" -> "  ; 
    }

    cout<<endl; 

}