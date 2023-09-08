// finding the x^n in the logarithmic time complexity i.e in O(log(n)) time.
#include <iostream>
using namespace std;

int powerLogarithmic(int x, int n)
{
    if (n == 0)
        return 1;

    int pw_n2 = powerLogarithmic(x, (n / 2));
    int pw_n = (pw_n2 * pw_n2);

    if (n & 1)
        pw_n *= x;

    return pw_n;
}

int main()
{
    int x, n;
    cin >> x >> n;
    cout << powerLogarithmic(x, n);
}