#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>


int print_factors(int n)
{
    int i = 0; 
    for(i =1 ; i<=sqrt(n) ; i++)
    {
        if(!(n%i))
        {
            if(i!=(n/i)) printf("%d %d " , i , n/i) ; 
            else printf("%d " , i) ;
        }
    }
}


//Proper Divisors does't include the number n
int sum_of_all_proper_divisors(int n )
{
    int i = 0 , sum = 0 ; 
    for(i = 2 ; i<=sqrt(n) ; i++)
    {
        if(!(n%i))
            sum+=(i==n/i?i : i+(n/i)) ;
    }
    return sum+1 ;
}


int main(void)
{
    printf("%d" , sum_of_all_proper_divisors(30)) ;
}