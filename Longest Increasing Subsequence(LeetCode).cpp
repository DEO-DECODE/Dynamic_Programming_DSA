#include <bits/stdc++.h>
using namespace std;
// Longest Increasing Subsequence(LeetCode)
int f(int ind, int prev_Ind, vector<int> &nums, vector<vector<int>> &dp)
{
    if (ind >= nums.size())
        return 0;
    if (dp[ind][prev_Ind + 1] != -1)
        return dp[ind][prev_Ind + 1];
    // NotTake
    int notTake = 0;
    notTake = f(ind + 1, prev_Ind, nums, dp);
    // Take
    int take = 0;
    if (prev_Ind == -1 || nums[ind] > nums[prev_Ind])
    {
        take = 1 + f(ind + 1, ind, nums, dp);
    }
    return dp[ind][prev_Ind + 1] = max(take, notTake);
}
int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return f(0, -1, nums, dp);
}
    int lengthOfLIS2(vector<int>& nums) {
         int n = nums.size();
  vector<int> dp(n, 1);
  int maxm = 1;
  for (int i = 0; i < n; ++i)
  {
    for (int prev = 0; prev < i; ++prev)
    {
      if (nums[i] > nums[prev])
      {
        dp[i] = max(dp[i], 1 + dp[prev]);
      }
    }
    maxm=max(maxm, dp[i]);
  }
  return maxm;
    }
