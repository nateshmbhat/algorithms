#include<bits/stdc++.h>
using namespace std; 

// PROBLEM
// Given a cell phone keypad (specified by a mapping M that takes
// individual digits and returns the corresponding set of characters) and a number se-
// quence, return all possible character sequences (not just legal words) that correspond
// to the number sequence.

void conversion_helper(string phone , int low )
{
    vector<string> data = {"0" , "1" , "ABC" , "DEF" , "GHI" ,"JKL" , "MNO" , "PQRS" , "TUVW" , "XYZ" }  ;
    if(low==phone.size())
    {
        cout<<phone <<endl; 
    }

    else{
        for(int i =low ; i < phone.length() ; i++)
        {
            string temp = data[phone[i]-'0'] ; 
            for(int j = 0 ; j<temp.length() ; j++)
            {
                swap(phone[i]  , temp[j]) ; 
                conversion_helper(phone ,  low+1 ) ; 
                swap(phone[i]  , temp[j]) ; 
            }
        }
    }
}

void convert(string s)
{
    vector<string> mnemonics ; 
    conversion_helper( s, 0 ) ; 
}


int main(void)
{
    string s = "2276696" ; 
    convert(s) ; 
}