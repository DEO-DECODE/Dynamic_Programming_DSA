#include <bits/stdc++.h>
using namespace std;
// Word Break(LeetCode)
int wordBreakUtil(string s, unordered_map<string, int> &dp, vector<string> &wordDict)
{
    int sz = s.size();
    if (sz == 0)
        return 1;
    for (int i = 1; i <= sz; ++i)
    {
        string tempWord = s.substr(0, i);
        auto itr = find(wordDict.begin(), wordDict.end(), tempWord);
        if (itr != wordDict.end())
        {
            int x = wordBreakUtil(s.substr(i), dp, wordDict);
            if (x == 1)
                return dp[s] = 1;
        }
    }
    return dp[s] = -1;
}
bool wordBreak(string s, vector<string> &wordDict)
{
    unordered_map<string, int> dp;
    int val = wordBreakUtil(s, dp, wordDict);
    if (val == -1)
        return false;
    return true;
}
