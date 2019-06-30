#include<bits/stdc++.h>
using namespace std; 

vector<int> getLPS(const string& text)
{
    vector<int> lps ; 
    lps.push_back(0) ; 
    int k = 0; 

    for(int i =1 ; i < text.length() ; i++)
    {
        if(text[k]==text[i])k++ ; 
        else k=0 ; 
        lps.push_back(k) ;
    }
    return lps ; 
}


void matchString(string text , string pattern)
{
    vector<int> lps = getLPS(pattern) ; 
    int i = 0 , j = 0 ; 
    int back ; 
    while(i<text.length())
    {
        if(text[i]==pattern[j]) {j+=1 ;i+=1; }
        if(j==pattern.length())  { cout<< " pos : " << j ;  j= lps[j-1] ; } 
        else{
            j = lps[j-1] ; 
            if(j>0)i-=1 ; 
            else i+=1 ;
        }
    }

}


int main(void)
{
    string t = "abaabcababcdaabacdababcd"; 
    string p = "ababcd" ; 
    
    matchString(t, p) ; 
}
