/*
Awadesh Nautiyal
 in O(n^2) algorithms includes bubble sort,insersion sort, and selection sort algorithm.

 ref:
 https://csacademy.com/lesson/sorting/
 https://usaco.guide/bronze/intro-sorting?lang=cpp
https://www.geeksforgeeks.org/sorting-algorithms/
*/

#include <bits/stdc++.h>
using namespace std;

/*
Selection sort:-
In this algorithm, we need two arrays here, the first solution is based on building the sorted array from scrach:
take the smallest, place it at the beginning of the new array, and remove it from the old array.
since we need to find the minimum element N times, the number of operations is
N+(N+1)+(N-2)+...+1 = (N*(N+1))/2 = O(n^2)
*/
vector<int> Selection_sort(vector<int> v)
{
    vector<int> sorted; // the new array which is going to be returned

    while (v.size()) // till when the v does have element (s)
    {
        // finding the minimum element
        int index_min = 0;
        for (int i = 1; i < v.size(); i++)
        {
            if (v[i] < v[index_min])
                index_min = i;
        }
        // insert that next smallest element in the new array
        sorted.push_back(v[index_min]);

        // remove that next smallest element from the old array
        v.erase(v.begin() + index_min);
    }
    // return when all elements are sorted
    return sorted;
}

/*
 Insersion sort:-
 IN this algorithm we will need only one array,
 for this algorithm we will always assume that the first i elements are sorted, and
 insert (i+1)th value in its correct place. it is important to note that this
 algorithm runs in O(n) time on already sorted arrays, but it up to O(n^2) for a reverse array.
 the number of swaps in actully equal to the number of inversions
 (pairs of elments i,j with i<j but a[i]>a[j]) in the original array.
*/
// using call by reference
void Inser_sort(vector<int> &v)
{
    for (int i = 1; i < v.size(); i++)
    {
        // consider the element is currently on position j, and try to move it even furthur lef
        for (int j = i; j > 0; j--)
        {
            if (v[j] < v[j - 1])
                swap(v[j], v[j - 1]);
            else
                break;
        }
    }
}

/*
Bubble sort:-
The O(n^2)- timed sorting algorithm, the bubble sort is the one that behaves
the best on averege.
it initially assumes the array is sorted, then iterates over its elements searching for a pair of consecutive elemets that are inverted.
if it finds a pair, it swaps the elements and marks the array
as "NOT SORTED".
it continues to iterate over the array until a whole iteration goes without any swaps,
signaling that the array is sorted.
*/
vector<int> bubble_sort(vector<int> v)
{
    bool is_sorted; // this check is used to remember whether at least one swap

    // was executed in the last transversal
    do
    {
        is_sorted = true; // initially assuem the array to be sorted
        for (int i = 1; i < v.size(); i++)
        {
            if (v[i] < v[i - 1]) // there is a bubble here
            {
                is_sorted = false; // the array was not stored in this transversal
                swap(v[i], v[i - 1]);
            }
        }
    } while (!is_sorted); /*when is_sorted was still true at the end of the "for" loop,
   it means no elements were swapped, so the array is sorted */

    return v; // returning the final sorted array
}
int main()
{
    vector<int> check1 = {120, 4, 423, 76, 3, 9, 91, 0};
    vector<int> check2 = {120, 4, 423, 76, 3, 9, 91, 0};
    vector<int> check3 = {120, 4, 423, 76, 3, 9, 91, 0};

    // calling the selection sort function
    vector<int> ans1 = Selection_sort(check1);
    for (auto &it : ans1)
        cout << it << " ";

    cout << endl;

    // function call to insersion sort function
    Inser_sort(check2);
    for (auto &it : check2)
        cout << it << " ";

    cout << endl;

    // function call to bubble sort
    vector<int> ans2 = bubble_sort(check3);
    for (auto &it : ans2)
        cout << it << " ";

    return 0;
}