class Solution {
public:
    
int func(int row, int col1, int col2, vector<vector<vector<int>>> &dp, vector<vector<int>> &grid)
{
  // Invalid Location
  if (col1 < 0 || col1 >= grid[0].size() || col2 < 0 || col2 >= grid[0].size())
  {
    return -1e8;
  }
  if (row == grid.size() - 1)
  {
    if (col1 == col2)
      return grid[row][col1];
    else
      return grid[row][col1] + grid[row][col2];
  }
  if (dp[row][col1][col2] != -1)
    return dp[row][col1][col2];
  int maxm = -1e8;
  for (int mv1 = -1; mv1 <= 1; ++mv1)
  {
    for (int mv2 = -1; mv2 <= 1; ++mv2)
    {
      int value = 0;
      if (col1 == col2)
        value = grid[row][col1];
      else
        value = grid[row][col1] + grid[row][col2];
      value += func(row + 1, col1 + mv1, col2 + mv2, dp, grid);
      maxm = max(maxm, value);
    }
  }
  return dp[row][col1][col2] = maxm;
}
int cherryPickup(vector<vector<int>> &grid)
{
  int m = grid.size();
  int n = grid[0].size();
  vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
  return func(0, 0, n - 1, dp, grid);
}

};
