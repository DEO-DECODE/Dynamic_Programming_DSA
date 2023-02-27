#include <bits/stdc++.h>
using namespace std;
// Minimum number of deletions and insertions(GFG)
class Solution
{

public:
    int longestCommonSubsequence(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        // return lcs(n - 1, m - 1, dp, s, t);
        for (int i = 0; i <= n; ++i)
            dp[i][0] = 0;
        for (int j = 0; j <= m; ++j)
            dp[0][j] = 0;
        // Base cases done
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][m];
    }
    int minDistance(string word1, string word2)
    {
        int m = word1.length(), n = word2.length();
        return m + n - 2 * (longestCommonSubsequence(word1, word2));
    }
    int minOperations(string str1, string str2)
    {
        // Your code goes here
        return minDistance(str1, str2);
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

        Solution ob;
        cout << ob.minOperations(s1, s2) << "\n";
    }
    return 0;
}

// } Driver Code Ends
