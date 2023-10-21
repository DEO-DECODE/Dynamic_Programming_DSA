//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string text1, string text2)
{
  int n1 = text1.size(), n2 = text2.size();
  vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
  // return func(n1 - 1, n2 - 1, dp, text1, text2);
  for (int ind1 = 1; ind1 <= n1; ++ind1)
  {
    for (int ind2 = 1; ind2 <= n2; ++ind2)
    {

      int match = 0, notMatch = 0;
      if (text1[ind1 - 1] == text2[ind2 - 1])
      {
        match = 1 + dp[ind1 - 1][ind2 - 1];
      }
      else
      {
        notMatch = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
      }
      dp[ind1][ind2] = max(match, notMatch);
    }
  }
  int len = dp[n1][n2];
  string ans = "";
  for (int i = 0; i < len; ++i)
  {
    ans += '*';
  }
  int ind1 = n1, ind2 = n2, index = len - 1;
  while (ind1 > 0 && ind2 > 0)
  {
    if (text1[ind1 - 1] == text2[ind2 - 1])
    {
      ans[index] = text1[ind1 - 1];
      ind1--, ind2--;
      index--;
    }
    else if (dp[ind1 - 1][ind2] > dp[ind1][ind2 - 1])
    {
      ind1--;
    }
    else
    {
      ind2--;
    }
  }
  cout << ans << endl;
  return 0;
}
int main()
{
  string s1 = "abxdabcyz", s2 = "acbabcjk";
  cout << longestCommonSubsequence(s1, s2);
}
