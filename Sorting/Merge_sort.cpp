/*
Awadesh nautiyal
Sorting and array in O(nlog(n)):- merge sort
*/

#include <bits/stdc++.h>
using namespace std;

/*
merge sort:-
 The merge sort algorithm is based on a divide and conquer strategy.
Breaking down a list intoo several sub-list until sublist consist of a single
element and merging those sublist in a manner that results into a sorted list.

IDEA:-
 - Divide the unsorted list into N sublist, each containing 1 element
 - Take adjacent pairs of two singleton list and merge them to form a lsit of 2 elements. N will now convert into N/2 list of size 2.
 - Repeat the process till a single sorted list is obtained.

 The way this algorithm runs is
 1. Divide
 2. Solve by recursion (Conquer)
 3. Combine
*/

int main()
{
    vector<int> a = {32, 54, 8, 4, 34, 23, -32, 43, 0};

    for (auto &it : a)
        cout << it << endl;

    cout << endl;

    merge_sort(a);

    for (auto &it : a)
        cout << it << endl;

    return 0;
}