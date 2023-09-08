example problem:-
https://codeforces.com/problemset/problem/1737/A

In this problem, we work on the Ascci values and Concept of MEX which is used in Various problems In competitive programing.

so Here it is.

MEX as stated in the problem is minimum excluded. It is the smallest value of a complete sequence, which in this case is a sequence of characters, is not present in the current sequence. For example if there is a sequence of non-negative integers 
1 2 4 0 6 10 
then the MEX for this sequence would be 3 which is obtained by comparing each number in the sequence 0 1 2 3 4 5 6 ... (basically all non negative integers) and checking if it is present or not. The smallest number that isn't present is considered the MEX.

For the above sequence, after sorting, 
0 1 2 4 6 10
and comparing it with 
0 1 2 3 4 5 6 7 ... 

It can be seen clearly that 3 is absent.

For the given problem, we are considering MEX of an alphabetical sequence, so it would be the first letter from 
a b c d e f ... z 
that is not present in the sequence 


--->

```c++
 // Solution to the problem
typedef long long ll;
void solve()
{
    ll n, k;
    string s;
    cin >> n >> k >> s;

    vector<char> ans;

    map<ll, ll> freq;
    for (auto it : s)
        freq[it - 'a']++;

    ll m = (n / k);
    for (ll i = 0; i < m; i++)
        while (k - ans.size() > freq[i])
            ans.push_back(i + 'a');

    char c = 'a' + m;

    while (k > ans.size())
        ans.push_back(c);

    reverse(ans.begin(), ans.end());

    for (auto it : ans)
        cout << it;

    cout << endl;
}
```


In line 12 we are subtracting one ascii value from another which gives us difference between the two ascii values.
In line 17 and 19, we are adding an integer to a character which is actually addition of the ascii value of that character and the integer and then the new character obtained corresponds to the new ascii value.

Deeper Explanation
Now talking about the ascii values, I hope you've seen an ascii chart before, if not I'm attaching one. Basically by subtracting an ascii from another ascii we obtain the difference between their position on the ascii chart. Here what we are doing is for each character of string s (which in this case would always be between 'a' to 'y')  we are subtracting a from it, which gives us the difference  of that character from a. Now this value is useful as it can be used to store value the keys as integers instead of characters. It becomes more useful if we use it as an index of an array instead of a map. Since the value of 'a' on the ascii table is 97 so if we do something like arr['a'] we would be accessing the 97th index of array arr. (PS: The character is automatically converted to an integer here, this is done by compiler). However if we do something like arr['a' - 'a'] it would be arr[0] which i think is quite apparent. So now we are accessing 0th index instead of 97th. You can see how the ascii values are subtracted. Right? 
Similarly adding an integer to a character changes the ascii value of that character by an amount that is equal to that integer. 

One nice thing to note is you can convert an int to a char and a char to an int as long as the values are within the domain of char (something around -128 to 127, not sure maybe 0 to 127, something similar), simply by

```c++
char c = 97; // This will correspond to 'a'
c = 65 + 2; // This will correspond to 'A' + 2 = 'C'
// Look up the ascii table for making a sense out of this
int z = c; // This will equal to ascii value of 'C' which is 67.
```

![ASCII Table](https://cdn.discordapp.com/attachments/1059055548957478932/1059119925899300874/ascii-table.png)

Talking about the solution, to obtain a lexicographically largest string the first character must be as big as it can be then the next should be as big as it can be and so on. As we learnt about the concept of MEX above, inorder to get the largest character at the first index, which is obtained by taking the MEX of the sequence of characters of the first compartment, what would be the most optimal approach? Does taking a continuous sequence is optimal? Think about it and then ping if you still can't get it.

