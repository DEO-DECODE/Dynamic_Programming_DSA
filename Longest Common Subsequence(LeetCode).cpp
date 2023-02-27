#include <bits/stdc++.h>
using namespace std;
// Longest Common Subsequence(LeetCode)
int f(int ind1, int ind2, vector<vector<int>> &dp, string &text1, string &text2)
{
    if (ind1 < 0 || ind2 < 0)
        return 0;
    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];
    // Case of Match
    int match = 0, NotMatch = 0;
    if (text1[ind1] == text2[ind2])
    {
        match = 1 + f(ind1 - 1, ind2 - 1, dp, text1, text2);
    }
    else
    {
        NotMatch = max(f(ind1 - 1, ind2, dp, text1, text2), f(ind1, ind2 - 1, dp, text1, text2));
    }
    return dp[ind1][ind2] = max(match, NotMatch);
}
int longestCommonSubsequence(string text1, string text2)
{
    int n1 = text1.size(), n2 = text2.size();
    vector<vector<int>> dp(n1, vector<int>(n2, -1));
    return f(text1.size()-1, text2.size()-1, dp, text1, text2);
}
