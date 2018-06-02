#include <bits/stdc++.h>

using namespace std;

// Complete the makingAnagrams function below.
int makingAnagrams(string s1, string s2) {

    map <char , int> M1 ;
    
    for(int i =0 ; i<s1.length() ; i++)
        M1[s1[i]] = M1[s1[i]]+1 ;
    for(int i =0 ; i<s2.length() ; i++)
        M1[s2[i]]--  ; 
    
    
    int sum =0 ; 
    for(int i =0 ; i<s1.length() ; i++)
        sum+= abs(M1[s1[i]]) ;
                  
    return sum ; 
}

int main()
{

    string s1;
    getline(cin, s1);
    // s1 = "abc" ;

    string s2;
    getline(cin, s2);
    // s2 = "cde" ;

    int result = makingAnagrams(s1 , s2 );

    cout<< result  <<endl ; 


    return 0;
}
