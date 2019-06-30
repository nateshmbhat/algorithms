#include<bits/stdc++.h>

using namespace  std ; 

#ifndef Array_UTILS_H
#define Array_UTILS_H

template <class Type>
class MyArray{
    public : 
    vector<Type> A ; 

    MyArray(int size , bool sort=false , string type="random"  , int start = 1, int end = 30) ; 

    Type operator[](Type) ; 

    template <class Type1>
    friend std::ostream& operator<<(std::ostream& , const MyArray<Type1>& ) ; 
};

#endif