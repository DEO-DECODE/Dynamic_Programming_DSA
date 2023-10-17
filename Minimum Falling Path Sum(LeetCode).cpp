class Solution {
public:
    int dpminfallingpath(vector<vector<int>> &dp, int i, int j, vector<vector<int>> &matrix)
{
    // Out of Bound Condition first.
    if (i < 0 || j < 0 || j >= matrix.size())
        return 1e5;
    if (i == 0)
        return matrix[i][j];
    if (dp[i][j] != -1)
        return dp[i][j];
    int TopMove = matrix[i][j] + dpminfallingpath(dp, i - 1, j, matrix);
    int TopLeftDiag = matrix[i][j] + dpminfallingpath(dp, i - 1, j - 1, matrix);
    int TopRightDiag = matrix[i][j] + dpminfallingpath(dp, i - 1, j + 1, matrix);
    return dp[i][j] = min(TopLeftDiag, min(TopRightDiag, TopMove));
}
int minFallingPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m,-1));
    int ans=INT_MAX;
    for(int j=0; j<m; ++j)
    ans=min(ans,dpminfallingpath(dp,n-1,j,matrix));
    return ans;
}

};
