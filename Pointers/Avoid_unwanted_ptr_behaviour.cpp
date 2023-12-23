#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Initialize an integer variable x with the value 32
    int x = 32;

    // Declare a pointer variable ptr and store the address of x in it
    int *ptr = &x;


    // ------concept of memory shift-----------------
    int a = 43;
    int *ptrA = &a;

    (ptrA)++; // this will go to next memory space, let say if address was 100 then it will go to 104,
    // since an integer carray 4 bytes in memory, so this poiner will will point to next address location, 
    // and not the 101 it will be 104.
    // the memory shif will be in the accordance to what type of pointer variable it is.
    //-------------------------------------------------------


    // Increment the value of x by 1 (post-increment)
    x++;
    cout << "Expected value:(33)" << " actual value: " << x << endl;

    // Increment the value of x by 1 (pre-increment)
    ++x;
    cout << "Expected value:(34)" << " actual value: " << x << endl;

    // Increment the value of x by 1 using the addition operator
    x = x + 1;
    cout << "Expected value:(35)" << " actual value: " << x << endl;

// -----------------------------Avoid these two -------------------------------------------

    // Post-increment the value pointed to by ptr (not the pointer itself)
    *ptr++;
    cout << "Expected value:(36)" << " actual value: " << x << endl; // actual 35

    // Pre-increment the value pointed to by ptr (not the pointer itself)
    ++*ptr;
    cout << "Expected value:(37)" << " actual value: " << x << endl; // actual 35

//----------------------------------------------------------------------------------------------


    // Increment the value pointed to by ptr using the addition operator (but not updating x)
    // if you want to do it, do it before the wrong "*ptr++ and "++*ptr" statements for desired results.
    *ptr = *ptr + 1;
    cout << "Expected value:(38)" << " actual value: " << x << endl; // actual 35

    /*
        what is i want to only ++ things only, then use braces '()' to wrap that pointer and then perform the 
        operation
    eg
    */

    ++(*ptr);
    cout << x << endl;   // this will give you correct expected results, since you've wrapped the *ptr inside ()

    (*ptr)++;
    cout << x << endl; // this will give you correct expected results, since you've wrapped the *ptr inside ()

    return 0;
}

/** Explanation:
1. The code starts with initializing x to 32 and declaring a pointer ptr pointing to x.

2. Three different ways of incrementing x by 1 are demonstrated, and the expected and actual values are printed.

3. In the 4th case (*ptr++), the post-increment operation is used on the value pointed to by ptr. However, due to operator precedence, ptr is first incremented, and then the original value is used. So, it does not affect the value of x.

4. In the 5th case (++*ptr), the pre-increment operation is used on the value pointed to by ptr. Again, due to precedence, the original value is first incremented, but it does not affect x.

5. In the 6th case (*ptr = *ptr + 1), the value pointed to by ptr is incremented, but the result is not assigned back to x. Therefore, x remains 35, and the expected and actual values are not the same.

The unwanted behavior in the 6th case is due to not updating the value of x after incrementing the value pointed to by ptr. If you want x to be updated, you should use *ptr = *ptr + 1  or ++(*ptr)  or (*ptr)++;
*/
