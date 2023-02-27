#include <bits/stdc++.h>
using namespace std;
// Minimum Insertion Steps to Make a String Palindrome(LeetCode)
int minInsertions(string s)
{
    string str1 = s;
    int n = s.length();
    reverse(s.begin(), s.end());
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    // return f(n - 1, n - 1, dp, str1, s);
    // base case
    for (int i = 0; i <= n; ++i)
        dp[i][0] = 0;
    for (int j = 0; j <= n; ++j)
        dp[0][j] = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (str1[i - 1] == s[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return str1.length() - dp[n][n];
}
