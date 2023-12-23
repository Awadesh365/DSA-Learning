#include <bits/stdc++.h>
using namespace std;

int main()
{

    // mistake
    int *ptr;
    /*
        if you have initialize it make sure you assign a value at
        the run time, 
        if there is any use of it, just initialize it at the time
        when it requred 
        or you have to initialize it anyway sometimes 
        so it's better to initialize it with nullptr to avoid 
        garbadge value or any unwanted exceptions or any
        other production issues.
    */

   // better way if you are initializing it but not storing anything currently.
   // then do it this way.

    int *ptr2 = nullptr;
    // this is known as null pointer, which will make sure this is null at the begining.

    return 0;
}