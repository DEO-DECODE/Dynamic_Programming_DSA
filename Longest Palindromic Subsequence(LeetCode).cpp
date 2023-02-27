#include <bits/stdc++.h>
using namespace std;
// Longest Palindromic Subsequence(LeetCode)
class Solution
{
public:
    int f(int ind1, int ind2, vector<vector<int>> &dp, string s1, string s2)
    {
        if (ind1 < 0 || ind2 < 0)
            return 0;
        if (dp[ind1][ind2] != -1)
            return dp[ind1][ind2];
        // match
        if (s1[ind1] == s2[ind2])
            return dp[ind1][ind2] = 1 + f(ind1 - 1, ind2 - 1, dp, s1, s2);
        return dp[ind1][ind2] = max(f(ind1 - 1, ind2, dp, s1, s2), f(ind1, ind2 - 1, dp, s1, s2));
    }
    int longestPalindromeSubseq(string s)
    {
        string str1 = s;
        int n = s.length();
        reverse(s.begin(), s.end());
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        // return f(n - 1, n - 1, dp, str1, s);
        // base case
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
        return dp[n][n];
    }
};
