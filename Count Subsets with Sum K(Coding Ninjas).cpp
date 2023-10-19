
const int mod=1e9+7;
int f(int ind, int sum, vector<int> &num, vector<vector<int>> &dp)
{
  if (ind < 0)
    return sum == 0;
  if (dp[ind][sum] != -1)
    return dp[ind][sum]%mod;
  int nottake = f(ind - 1, sum, num, dp);
  int take = 0;
  if (num[ind] <= sum)
    take = f(ind - 1, sum - num[ind], num, dp);
  return dp[ind][sum] = (nottake + take)%mod;
}
int findWays(vector<int> &num, int sum)
{
  // Write your code here.
  int n = num.size();
  vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
  return f(n - 1, sum, num, dp);
}
