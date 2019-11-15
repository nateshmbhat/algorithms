
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<ctype.h>
#include<sys/time.h>
#include<time.h>

void insertionSort(int a[] , int n )
{
	int i =0 , j ,  key ;

	for(i =1 ; i < n ; i++)
	{
		j = i-1 ;
		key = a[i] ;
		while(j>=0 && a[j]>key){
			a[j+1] = a[j] ; 
			j-=1 ;
		} 
		a[j+1] = key ; 
	}
}



void genRand(int a[] , int n )
{
	int i ; 
	for(i=0 ; i < n ; i++)
	{
		a[i] = rand()%100 ; 
	}
}

void display(int a[] , int n )
{
	int i = 0; 
	for(i=0 ; i< n ;i++) printf("%d " , a[i]) ; 
	printf("\n\n") ; 
}


void userInteract(int a[] , int n )
{

	printf("\nEnter size of random array : ") ; 
	scanf("%d" , &n) ; 

	genRand(a , n ) ; 

	printf("Array is : \n" ) ;
	display(a , n ) ; 
	insertionSort(a , n ) ; 
	display(a , n) ;
}


int main(void)
{
	srand(time(NULL)) ; 
	int size = 16000 ; 
	int * a  = malloc(size * sizeof(int)) ; 
	int i = 0 , n = 20 ; 
	struct timeval tv ; 
	double s, e ;
	printf("\n1. Plot graph\t2.InsertionSort\t3.Exit\nEnter choice : ") ; 
	int ch ;
	FILE * fp ; 

	scanf("%d" , &ch) ; 

	switch(ch)
	{
		case 1:

				
			fp = fopen("insertionSort.dat" , "w") ; 

			for(i=100 ; i<size ; i+=100)
			{
				printf("i = %d\n" , i) ; 

				gettimeofday(&tv , NULL ) ; 
				genRand(a , i ) ; 
				s = tv.tv_sec + tv.tv_usec/1000000.0 ; 
				insertionSort(a ,i ) ;
				gettimeofday(&tv , NULL ) ;  
				e = tv.tv_sec + tv.tv_usec/1000000.0 ; 
				fprintf(fp , "%d\t%f\n" , i , e-s) ; 
			}

				fclose(fp) ;
			break ;

		case 2 : 
			userInteract(a , n) ;
			break ; 			

		default : exit(1) ; 
	}

}
