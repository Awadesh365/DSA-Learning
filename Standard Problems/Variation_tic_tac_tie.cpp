
// Team Tic Tac Toe USACO :-http://www.usaco.org/index.php?page=viewproblem2&cpid=831
// accessing the multidimentaional array like a simple array

// array of multidimentional set
set<set<char>> ans[4];

ll cnt = 0, pnt = 0;

void test(char a, char b, char c)
{
    set<char> s;
    s.insert({a, b, c});

    // inseting values wheather ans[1]  or ans[2]  only
    if (s.size() == 1)
        ans[1].insert(s);
    else if (s.size() == 2)
        ans[2].insert(s);
}

void solve()
{
    char a1, a2, a3;
    char a4, a5, a6;
    char a7, a8, a9;
    cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6 >> a7 >> a8 >> a9;

    test(a1, a2, a3);
    test(a4, a5, a6);
    test(a7, a8, a9);
    test(a1, a4, a7);
    test(a2, a5, a8);
    test(a3, a6, a9);
    test(a1, a5, a9);
    test(a3, a5, a7);

    cout << ans[1].size() << endl
         << ans[2].size();
}
int main()
{
    setIO("tttt");
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // precompute();

    // ll TESTS;
    // cin >> TESTS;
    // while (TESTS--)
    solve();

    return 0;
}