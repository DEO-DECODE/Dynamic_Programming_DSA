class Solution {
public:
int func(int index, int amount, vector<vector<int>> &dp, vector<int> &coins)
{
  if (index == 0)
  {
    if (amount % coins[0] == 0)
    {
      return amount / coins[0];
    }
    return 1e8;
  }
  if(dp[index][amount]!=-1) return dp[index][amount];
  int take = 1e8, notTake = 1e8;
  if (coins[index] <= amount)
  {
    take = 1 + func(index, amount - coins[index], dp, coins);
  }
  notTake = func(index - 1, amount, dp, coins);
  return dp[index][amount] = min(take , notTake);
}
int coinChange(vector<int> &coins, int amount)
{
  int n = coins.size();
  vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
  int ans= func(n - 1, amount, dp, coins);
  if(ans>=1e8) return -1;
    return ans;
}
};
