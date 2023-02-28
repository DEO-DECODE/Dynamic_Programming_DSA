#include <bits/stdc++.h>
using namespace std;
// Distinct Subsequences(LeetCode)
int f(string &s, string &t, vector<vector<int>> &dp, int ind1, int ind2)
{
    if (ind2 < 0)
        return 1;
    if (ind1 < 0)
        return 0;
    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];
    // Match
    int match = 0, notMatch = 0;
    if (s[ind1] == t[ind2])
    {
        match = f(s, t, dp, ind1 - 1, ind2 - 1) + f(s, t, dp, ind1 - 1, ind2);
    }
    else
    {
        notMatch = f(s, t, dp, ind1 - 1, ind2);
    }
    return dp[ind1][ind2] = max(match, notMatch);
}
int numDistinct(string s, string t)
{
    int ns = s.size(), nt = t.size();
    // Recursive
    // vector<vector<int>> dp(ns, vector<int>(nt, -1));
    // return f(s, t, dp, ns - 1, nt - 1);
    // Tabulation
    vector<vector<long long int>> dp(ns+1, vector<long long int> (nt+1,0));
    for(int i=0; i<=ns; ++i) dp[i][0]=1;
    for(int i=1; i<=ns; ++i){
        for(int j=1; j<=nt; ++j){
            if(s[i-1]==t[j-1]){
                dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[ns][nt];
}
