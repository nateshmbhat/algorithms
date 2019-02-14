#include<bits/stdc++.h>

using namespace std ; 

typedef struct{
    bool palindromeFlag   ; 
    int length ; 
}Result ;


Result findLengthOfLongestPalindromicSubString(string s , int start , int end ){
    if(start==end){//single length string is a palindrome of length 1
        Result res = {true , 1} ; 
        return res ;
    } 
    if(start>end){
        Result res = {true , 0 } ; 
        return res ; 
    }
    
    Result left = findLengthOfLongestPalindromicSubString(s , start , end-1) ; 
    Result right = findLengthOfLongestPalindromicSubString(s , start+1 , end) ; 

    if(s[start]==s[end]){
            Result inside = findLengthOfLongestPalindromicSubString(s ,start+1 , end-1) ; 
            inside.length+=2 ; 
            if(inside.palindromeFlag==true) return inside ; 
    }
    
    Result res = {false, max(left.length , right.length)} ; 
    return res ; 
}

bool checkPalindrome(string s , int a , int b){
    if(a>=b)return true ; 
    else if(s[a]==s[b]) return checkPalindrome(s , a+1 , b-1) ; 
    else return false ; 
}

int findLongestPalindromicSubString(string s ){
    string temp ; 
    int maxval = 1 ;
    string maxstring ; 
    for(int i = 0  ; i < s.length()-1 ; i++){
        for(int j =i+1 ; j <=s.length() ; j++){
            temp = s.substr(i, j-i ) ; 
            if(checkPalindrome(temp , 0 , temp.length()-1))
            {
                if(maxval< temp.length())
                {
                    maxval = temp.length() ; 
                    maxstring = temp ;
                }
            }
        }
    } 
    cout<<maxstring ; 
    return maxval  ;
}


int main(){
    string s;
    cin>>s ; 
    int res = findLongestPalindromicSubString(s) ; 
    cout<<res<<endl  ; 

    }