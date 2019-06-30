// find all substrings of digits from a given string that sum to 10
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
    char s[100];
    printf("Enter string : " ) ; 
    scanf("%s", s);

    for (int i = 0; i < strlen(s) - 1; i++)//start position of the substring
    { 
        for (int j = i + 1; j < strlen(s); j++)//end pointer of substring
        { 
            int sum =0 ; 
            for(int k =i ; k<=j ; k++) sum+=s[k]-'0' ; 
            
            if(sum==10){
                for(int k =i ; k<=j ; k++) printf("%c" , s[k]) ; 
                printf("\n") ; 
            }
        }
    }
}