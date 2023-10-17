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
bool subsetSumToK(int n, int k, vector<int> &arr)
{
  vector<vector<int>> dp(n, vector<int>(k + 1, -1));
  return func(n - 1, k, dp, arr);
}
