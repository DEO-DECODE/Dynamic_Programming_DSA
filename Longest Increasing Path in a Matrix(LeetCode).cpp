#include <bits/stdc++.h>
using namespace std;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool isvalid(int r, int c, vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    return r >= 0 && r < n && c >= 0 && c < m;
}
int ans = 0;
int traverse(vector<vector<int>> &matrix, int i, int j, vector<vector<int>> &dp)
{
    if (dp[i][j] != -1)
        return dp[i][j];
    int temp = matrix[i][j];
    matrix[i][j] = -1;
    int ans = 1;
    for (int move = 0; move < 4; ++move)
    {
        int childX = i + dx[move];
        int childY = j + dy[move];
        if (!isvalid(childX, childY, matrix))
            continue;
        if (matrix[childX][childY] == -1)
            continue;
        if (matrix[childX][childY] > temp)
            ans = max(ans, 1 + traverse(matrix, childX, childY, dp));
    }
    matrix[i][j] = temp;
    return dp[i][j] = ans;
}
int longestIncreasingPath(vector<vector<int>> &matrix)
{
    int finans = 0;
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[0].size(); ++j)
        {
            ans = traverse(matrix, i, j, dp);
            finans = max(finans, ans);
        }
    }
    return finans;
}
