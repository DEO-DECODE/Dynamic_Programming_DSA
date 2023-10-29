class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
 int n = nums.size(), maxm = 1, ans = 0;
  vector<int> dp(n, 1), cnt(n, 1);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < i; ++j)
    {
      if (nums[i] > nums[j])
      {
        if (dp[i] < dp[j] + 1)
        {
          cnt[i] = cnt[j];
          dp[i] = dp[j] + 1;
          maxm = max(maxm, dp[i]);
        }
        else if (dp[i] == dp[j] + 1)
        {
          cnt[i] += cnt[j];
        }
      }
    }
  }
  for (int i = 0; i < n; ++i)
  {
    // cout << dp[i] << " " <<cnt[i]<<endl;
    if (dp[i] == maxm)
    {
      ans+=cnt[i];
    }
  }
  // cout << endl;
  return ans;
    }
};
