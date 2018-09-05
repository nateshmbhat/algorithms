#include<bits/stdc++.h>
using namespace std; 

string normalize_path(string path)
{
    string res ;
    stack<string> stk ; 
    int startpos = 0 ;

    if(path[0]=='/') stk.push('/') ; 
    
    int pos = path.find('/' , 1) ;
    while(pos> 0)
    {
            
    }


    return res ; 
}

int main()
{
    string path = "sc//././../tmk/awk/../../hi/howru" ; 
    string normalPath= normalize_path(path) ; 
    cout<<normalPath ; 
}