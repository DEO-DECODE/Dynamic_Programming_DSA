class Solution {
public:
    int func(int target, int curStep, vector<int> &dp)
{
  if (curStep == target)
  {
    return 1;
  }
  else if (curStep > target)
    return 0;
  if (dp[curStep] != -1)
    return dp[curStep];
  return dp[curStep] = (func(target, curStep + 1, dp)+ func(target, curStep + 2, dp));
}
int climbStairs(int n)
{
  vector<int> dp(n+1, -1);
  return func(n, 0, dp);
}
};
