#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
    since the formula of finding area of rectangle is (width*Length)
    length is the length of the vertical sides |
    and width is the length of the horizontal sides. __
    let top right and bottom left of a rectangle be tr and bl and the sides be tr_x, tr_y, bl_x, bl_y

    1-> width = tr_x - bl_x
    2-> length = tr_y - bl_y
    3-> area = (width*length)
*/
// function to find the area of rectangle using the top right and bottom left points.
ll find_area(ll tr_x, ll tr_y, ll bl_x, ll bl_y)
{
    ll width = tr_x - bl_x;
    ll length = tr_y - bl_y;
    ll area = width * length;

    return area;
}