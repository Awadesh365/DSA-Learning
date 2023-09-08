#include <iostream>
using namespace std;

// first n, (n-1), (n-2), (n-3)... 1
// then 1 , 2, ... n
void printIncDec(int n)
{
    if (n == 0)
        return;
    cout << n << endl;
    printIncDec(n - 1);
    cout << n << endl;
}

int main()
{
    int n;
    cin >> n;
    printIncDec(n);
}
