#include <bits/stdc++.h>
using namespace std;
int func(vector<int> &wt, vector<int> &val, int ind, int W, vector<vector<int>> &dp)
{
  if (ind == 0)
  {
    return (W / wt[0]) * val[0];
  }
  if (dp[ind][W] != -1)
    return dp[ind][W];
  int notTaken = 0 + func(wt, val, ind - 1, W, dp);
  int taken = 0;
  if (wt[ind] <= W)
    taken = val[ind] + func(wt, val, ind, W - wt[ind], dp);
  return dp[ind][W] = max(notTaken, taken);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
  // Write Your Code Here.
  vector<vector<int>> dp(n, vector<int>(w + 1, -1));
  return func(weight, profit, n-1, w, dp);
}
