#include <bits/stdc++.h>
using namespace std;

/**
    *  Does not matter what will be the datatype of the pointer, the size of the pointer
    * will remain as constant 8,
    * might be it may vary to some architechure of systems,
    * but in most of the cases it will be 8.
    * use sizeof(ptr) function to find out the size of pointer.

    * In C and C++, the size of a pointer variable depends on the architecture of the system.
    * On a 32-bit system, a pointer typically occupies 4 bytes, while on a 64-bit system,
    * it usually occupies 8 bytes.
    * The reason for this difference is that a pointer is meant to store memory addresses,
    * and the size of a memory address is determined by the architecture of the system. In a 32-bit system,
    * memory addresses are 32 bits (4 bytes), and in a 64-bit system, memory addresses are 64 bits (8 bytes).
    * However, it's essential to note that the actual size may vary on different systems and compilers.
    * You can use the sizeof operator in C or C++ to determine the size of a pointer on a specific system.
    */
int main()
{

    struct first
    {
        int x = 32;
        vector<int> items;
        vector<vector<vector<int>>> testVec;
    };

    first myStr;

    first *ptr0 = &myStr; // pointer of struct type

    vector<string> list = {"abc", "def", "ghi"};

    vector<string> *ptr1 = &list; // pointer of vector<string> type

    int num = 1e4;
    int *ptr2 = &num; // pointer of int type

    double numDub = 32.43;
    double *ptr3 = &numDub; // pointer of double type

    cout << sizeof(ptr0) << endl // 8
         << sizeof(ptr1) << endl // 8
         << sizeof(ptr2) << endl // 8
         << sizeof(ptr3);        // 8

    return 0;
}