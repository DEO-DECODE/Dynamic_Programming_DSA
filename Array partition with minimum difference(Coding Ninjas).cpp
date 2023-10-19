#include <bits/stdc++.h>
using namespace std;
bool func(int ind, int target, vector<vector<int>> &dp, vector<int> &arr)
{
  if (target == 0)
    return true;
  if (ind == 0)
    return arr[0] == target;
  if (dp[ind][target] != -1)
    return dp[ind][target];
  bool notTake = func(ind - 1, target, dp, arr);
  bool take = false;
  if (arr[ind] <= target)
  {
    take = func(ind - 1, target - arr[ind], dp, arr);
  }
  return dp[ind][target] = take || notTake;
}

int minSubsetSumDifference(vector<int> &arr, int n)
{
  // Write your code here.
  int totalSum = accumulate(arr.begin(), arr.end(), 0);
  vector<vector<int>> dp(n, vector<int>(totalSum + 1, -1));
  for (int sm = 0; sm <= totalSum; ++sm)
  {
    func(n - 1, sm, dp, arr);
  }
  int mini = 1e9;
  for (int sm = 0; sm <= totalSum / 2; ++sm)
  {
    if (dp[n - 1][sm] == 1)
    {
      mini = min(mini, abs(sm - (totalSum - sm)));
    }
  }
  return mini;
}
