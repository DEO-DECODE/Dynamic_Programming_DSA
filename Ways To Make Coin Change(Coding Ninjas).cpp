#include <bits/stdc++.h>
using namespace std;


long long func(int index, int amount, vector<vector<long long>> &dp, int *coins)
{
  if (index == 0)
  {
    return (amount % coins[0] == 0);
  }
  if(dp[index][amount]!=-1) return dp[index][amount];
  long long take = 0, notTake = 0;
  if (coins[index] <= amount)
  {
    take = func(index, amount - coins[index], dp, coins);
  }
  notTake = func(index - 1, amount, dp, coins);
  return dp[index][amount] = take + notTake;
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
  // Write your code here
  vector<vector<long long>> dp(n, vector<long long>(value + 1, -1));
  return func(n - 1, value, dp, denominations);
}
