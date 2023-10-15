class Solution {
public:
    int func(int r, int c, int m, int n, vector<vector<int>> &dp, vector<vector<int>> &obstacleGrid)
{
  if (r == m - 1 && c == n - 1)
    return 1;
  if(obstacleGrid[r][c]==1) return 0;
  if (dp[r][c] != -1)
    return dp[r][c];
  int downMove = 0, rightMove = 0;
  if (r + 1 <= m - 1)
  {
    downMove = func(r + 1, c, m, n, dp, obstacleGrid);
  }
  if (c + 1 <= n - 1)
  {
    rightMove = func(r, c + 1, m, n, dp, obstacleGrid);
  }
  return dp[r][c] = downMove + rightMove;
}
int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
  int m = obstacleGrid.size(), n = obstacleGrid[0].size();
  if(obstacleGrid[m-1][n-1]==1) return 0;
  vector<vector<int>> dp(m, vector<int>(n, -1));
  return func(0, 0, m, n, dp, obstacleGrid);
}

};
