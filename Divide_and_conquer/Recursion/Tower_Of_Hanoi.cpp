#include <iostream>
using namespace std;

void toh(int n, int a, int b, int c)
{
    if (n == 0)
        return;

    // left call
    toh((n - 1), a, c, b); // using b, transfer plates a to c
    cout << n << "[" << a << " -> " << b << "]" << endl;
    // right call
    toh((n - 1), c, b, a); // using a transfer plates from c to a and then a to b, it will does that automatically.
}

int main()
{
    int n;
    cin >> n;
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    toh(n, n1, n2, n3);
}