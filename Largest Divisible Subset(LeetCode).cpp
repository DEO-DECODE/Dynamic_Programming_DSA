class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
   vector<int> dp(n, 1);
   vector<int> hash(n);
   vector<int> ans;
   sort(nums.begin(), nums.end());
   int maxim = 1, last_index = 0;
   for (int i = 0; i < n; ++i)
   {
      int len = 1;
      hash[i] = i;
      for (int j = 0; j < i; ++j)
      {
         if (nums[i] % nums[j] == 0 && 1 + dp[j] > dp[i])
         {
            dp[i] = 1 + dp[j];
            hash[i] = j;
         }
      }
      if (dp[i] > maxim)
      {
         maxim = dp[i];
         last_index = i;
      }
   }
   ans.push_back(nums[last_index]);
   while (last_index != hash[last_index])
   {
      last_index = hash[last_index];
      ans.push_back(nums[last_index]);
   }
   reverse(ans.begin(), ans.end());
   return ans;
    }
};
