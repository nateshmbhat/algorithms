#include<bits/stdc++.h>
using namespace std; 


void roman_to_decimal(string roman)
{
    unordered_map<char , int> M = {{'I'  , 1 } , {'V' , 5} , {'X' , 10 } , {'C' , 100} , {'L' , 50} , {'D' , 500} , {'M' , 1000 }} ; 
    string s ; 

    int sum = M[roman.back()] ; 

    for(int i = roman.length()-2 ; i>=0 ; i--)
    {
        sum+=(M[roman[i]]<M[roman[i+1]]? -M[roman[i]] : M[roman[i]]) ; 
    }

    cout<<sum <<endl; 
}

int main(void)
{
    string roman  = "CCCXLIII" ; 
    roman_to_decimal(roman) ; 
}