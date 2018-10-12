#include "utils.h" 

using namespace std ; 

template <class Type>
MyArray<Type>::MyArray(int size , bool sort , string type,  int start, int end ) 
{
    A.resize(size) ; 
    srand(time(NULL)) ; 

    for(int i =0 ; i < size ; i++)
    {
        A[i] = start  + rand()%(end-start) ; 
    }

    if(sort) std::sort(A.begin() , A.end()) ; 
}


template <class Type>
Type MyArray<Type>::operator[](Type x)
{
    return A[x] ; 
}



template <class Type1>
std::ostream& operator<<(ostream& out , const MyArray<Type1>& M)
{
    cout<<endl; 
    for(int i =0  ; i<M.A.size(); i++)
    {
        cout<<M.A[i]<<"\t" ; 
    }
    cout<<endl  ; 
    return out ; 
}
