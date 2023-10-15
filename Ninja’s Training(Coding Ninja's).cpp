#include <bits/stdc++.h>
using namespace std;
int func(int ind, int prevInd, vector<vector<int>> &points, vector<vector<int>> &dp)
{
  if (ind == 0)
  {
    int maxm = 0;
    for (int i = 0; i < 3; ++i)
    {
      if (i == prevInd)
        continue;
      maxm = max(maxm, points[0][i]);
    }
    return maxm;
  }
  if (dp[ind][prevInd] != -1)
    return dp[ind][prevInd];
  int maxPoints = 0;
  for (int in = 0; in < 3; ++in)
  {
    int point;
    if (in != prevInd)
    {
      point = points[ind][in] + func(ind - 1, in, points, dp);
      maxPoints = max(maxPoints, point);
    }
  }
  return dp[ind][prevInd] = maxPoints;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
  // Write your code here.
  vector<vector<int>> dp(n, vector<int>(4, -1));
  return func(n - 1, 3, points, dp);
}
