#include <bits/stdc++.h>

using namespace std;
int mem[26] = {0};
int memsub[26] = {0};

int check(string &s , int low , int high ){
    int l = high-low ;
    int res = 0 ;
    memset(mem, 0, 26*sizeof(int)) ;
    memset(memsub, 0, 26 * sizeof(int));

    for(int i = low; i < low+l; i++) mem[s[i] - 'a']++;
    for (int i = low; i < low+l; i++)
      memsub[s[i] - 'a'] = mem[s[i]-'a'] ;

    for(int i = 0 ;i < 26 ; i++)
        cout<<((char)((char)i+'a')) <<" - " << mem[s[i]-'a'] <<endl ;

    for (int i =low+1 ; i < s.length() - l+1 ; i++){
        memsub[s[i-1]-'a']-- ;
        memsub[s[i]-'a']++ ;

        cout << s.substr(low , l) <<endl; 
        cout << s.substr(i, l)<<  endl;

        // CHECK ANAGRAM 
        bool flag = true ;
        for(int k = 0 ; k<26 ; k++){
            if(memsub[k]!=mem[k]){
                flag = false ; break ;
            }
        }
        if(flag)cout<<"@@"<<endl; 
        cout<< "==============" <<endl; 
        if(flag)res+=1;
    }
    cout<<"|||||||||||||||||"<<endl; 
    return res ;
}


// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {
  int res = 0;
  for(int len = 1 ; len < s.length() ; len++){
    for(int j=0 ; j<=s.length()-len ; j++ ){
        // Substring = s.substring(j , j+len)
        res+=check(s, j , j+len  ) ;
    }
  }
  return res ;
}

int main()
{
    
    int q;
    cin >> q;

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        cin>>s ; 
        int result = sherlockAndAnagrams(s);

        cout << result << "\n";
    }
    return 0;
}
