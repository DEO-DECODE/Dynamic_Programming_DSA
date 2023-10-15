class Solution {
public:
    int f(vector<vector<int>> &grid, vector<vector<int>> &dp, int i, int j)
{
	if (i == 0 && j == 0)
	{
		return grid[i][j];
	}
	if (i < 0 || j < 0)
		return 500;
	if (dp[i][j] != -1)
		return dp[i][j];
	int topmove = grid[i][j] + f(grid, dp, i - 1, j);
	int leftmove = grid[i][j] + f(grid, dp, i, j - 1);
	return dp[i][j] = min(leftmove, topmove);
}
int minPathSum(vector<vector<int>> &grid)
{
	int m = grid.size();
	int n = grid[0].size();
	vector<vector<int>> dp(m, vector<int>(n, -1));
	return f(grid, dp, m - 1, n - 1);
}
};
