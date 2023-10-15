class Solution {
public:
    int f(int ind, vector<int> &dp, vector<int> &num)
{
    if (ind == 0)
        return num[0];
    if (ind < 0)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];
    // int non pick
    int non_pick = f(ind - 1, dp, num);
    int pick = num[ind] + f(ind - 2, dp, num);
    return dp[ind] = max(pick, non_pick);
}
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
    vector<int> nums1(n - 1), nums2(n - 1);
    for(int i=0; i<nums.size()-1; ++i) nums1[i]=nums[i];
    int ind=0;
    for(int i=1; i<nums.size(); ++i){
         nums2[ind]=nums[i];
         ind++;
    }
    vector<int> dp1(n - 1, -1), dp2(n - 1, -1);
    int ans1 = f(n - 2, dp1, nums1);
    int ans2 = f(n - 2, dp2, nums2);
    return max(ans1, ans2);
    }
};
