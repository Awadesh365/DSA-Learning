// Block Game usaco :- http://www.usaco.org/index.php?page=viewproblem2&cpid=664

const int N = 26;

void count_freq(const string &s, vector<int> &freq)
{
    for (auto c : s)
        freq[c - 'a']++;
}

void solve()
{
    int n;
    cin >> n;

    vector<int> ans(N);
    while (n--)
    {
        string s1, s2;
        cin >> s1 >> s2;

        vector<int> freq1(26), freq2(26);
        count_freq(s1, freq1);
        count_freq(s2, freq2);

        for (int i = 0; i < N; i++)
            ans[i] += max(freq1[i], freq2[i]);
    }

    for (auto i : ans)
        cout << i << endl;
}
