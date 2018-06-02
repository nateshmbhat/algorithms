#include<bits/stdc++.h>
using namespace std ; 


bool checkthis(string str)
{
 map<char , int >  M ; int temp ; 

 for(int i =0 ;i<str.length() ; i++)
    {
        M[str[i]]+=1 ;  
    }
   
  temp = M[str[0]]  ; 

  for(int i =1 ; i<str.length() ; i++)
  {
      if(M[str[i]]!=temp)
        return false; 
  }

  return true ; 

}



int main(void)
{
  int T ; string S , temp ;
  cin>> T; 
  int count =0 ; 
  
  for(int test_cases= 0 ; test_cases<T ;  test_cases++)
  {
  	cin>> S ; 
  	for(int i =0 ; i<S.length()-1; i++)
  	{
  	    for(int j =i+1 ; j<S.length() ; j++)
  	    {
  	    	if(checkthis(S.substr(i , j-i + 1)))
  	    		count+=1 ; 
  	    }
  	}
  
  }


}