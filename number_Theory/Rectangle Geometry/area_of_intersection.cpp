#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
  since  any shape formed by the intersection of two rectangles is itself a rectange.
  if anyhow the shape becomes the square, so we know that square itself is a special kind of recangle.

  let us find the rectangl's length and width.
  width = min(tr_a_x,tr_b_x) - max(bl_a_x,bl_x)
  length = min(tr_a_y,tr_b_y) - max(bl_a_y,bl_b_y)

  if either of these values ar negative, the rectangle do not interset.
  if they are zero the rectangles intersect at a single point.
  multiply the length and width to find the overlapping area.
*/
ll area_of_intersection(vector<ll> s1, vector<ll> s2)
{
    ll bl_a_x = s1[0], bl_a_y = s1[1], tr_a_x = s1[2], tr_a_y = s1[3];
    ll bl_b_x = s2[0], bl_b_y = s2[1], tr_b_x = s2[2], tr_b_y = s2[3];

    ll length = min(tr_a_x, tr_b_x) - max(bl_a_x, bl_b_x);
    ll width = min(tr_a_x, tr_b_y) - max(bl_a_y, bl_b_y);

    return (length * width);
}