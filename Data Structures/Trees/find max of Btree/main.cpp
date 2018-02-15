#include<bits/stdc++.h>
#include<list>
#include "../trees.h"

using namespace std ; 

int main(void)
{
    Tree temp(150) ; 
    Tree myt = temp.generateRandBST(10) ;

    cout<<myt ; 

    cout<<"\n" <<myt.findMax(myt.root) ; 
    cout<<endl<<myt.isBST(myt.root) ; 
    cout<<myt ; 
}