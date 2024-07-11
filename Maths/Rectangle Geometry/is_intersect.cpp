#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
Checking if two rectangles intersect
  let two rectangles ( in the vector form ) s1 and s2, let the coordinates of the rectangle s1 be (tr_a_x, tr_a_y) and (bl_a_x, bl_a_y)
  and similar with s2.
  there only two cases where they do not interset
  Case 1 -> tr_a_y <= bl_b_y or bl_a_y >= tr_b_y
  Case 2 -> bl_a_x >=tr_b_x or tr_a_x <= bl_b_x
*/
// a function which returns true if two rectangles intersect
bool is_intersect(vector<ll> s1, vector<ll> s2)
{
    bool ans = true;

    ll bl_a_x = s1[0], bl_a_y = s1[1], tr_a_x = s1[2], tr_a_y = s1[3];
    ll bl_b_x = s2[0], bl_b_y = s2[1], tr_b_x = s2[2], tr_b_y = s2[3];

    // NO overlap
    if (bl_a_x >= tr_b_x || tr_a_x <= bl_b_x || bl_a_y >= tr_b_y || tr_a_y <= bl_b_y)
        ans = false;

    return ans;
}