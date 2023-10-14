int func(int curStair, vector<int> &dp, int target, vector<int> &heights)
{
  if (curStair == target)
  {
    return 0;
  }
  if (curStair > target)
  {
    return 1e8;
  }
  if(dp[curStair]!=-1) return dp[curStair];
  int move1 = 1e8, move2 = 1e8;
  if (curStair + 1 <= target)
  {
    move1 = abs(heights[curStair + 1] - heights[curStair]) + func(curStair + 1, dp, target, heights);
  }
  if (curStair + 2 <= target)
  {
    move2 = abs(heights[curStair + 2] - heights[curStair]) + func(curStair + 2, dp, target, heights);
  }
  return dp[curStair] = min(move1, move2);
}
int frogJump(int n, vector<int> &heights)
{
  // Write your code here.
  vector<int> dp(n, -1);
  return func(0, dp, n - 1, heights);
}
