vector<int> printingLongestIncreasingSubsequence(vector<int> nums, int n) {
	// Write your code here
	int ans = 1, lastIndex;
  vector<int> dp(n, 1);
  vector<int> hash(n);
  for (int i = 0; i < n; ++i)
  {
    hash[i] = i;
    for (int j = 0; j < i; ++j)
    {
      if (nums[i] > nums[j] && dp[j] + 1 > dp[i])
      {
        dp[i] = dp[j] + 1;
        hash[i] = j;
      }
    }
    if (dp[i] > ans)
    {
      ans = dp[i];
      lastIndex = i;
    }
  }
  vector<int> ansLis;
  ansLis.push_back(nums[lastIndex]);
  while (hash[lastIndex] != lastIndex)
  {
    lastIndex = hash[lastIndex];
    ansLis.push_back(nums[lastIndex]);
  }
  reverse(ansLis.begin(), ansLis.end());
  
  return ansLis;
}
