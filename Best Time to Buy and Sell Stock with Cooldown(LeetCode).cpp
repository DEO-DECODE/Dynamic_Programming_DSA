#include <bits/stdc++.h>
using namespace std;
//Best Time to Buy and Sell Stock with Cooldown(LeetCode)
int bsswc(int ind, int n, int buy, vector<int> &prices, vector<vector<int>> &dp)
{
    if (ind >= n)
        return 0;
    if (dp[ind][buy] != -1)
        return dp[ind][buy];
    int profit = 0;
    if (buy == 1)
    {
        // Eligible to buy
        // We want to buy or we don't want to buy
        profit = max(-prices[ind] + bsswc(ind + 1, n, 0, prices, dp), 0 + bsswc(ind + 1, n, 1, prices, dp));
    }
    else
    {
        profit = max(+prices[ind] + bsswc(ind + 2, n, 1, prices, dp), 0 + bsswc(ind + 1, n, 0, prices, dp));
<!-- ind+2 is done bcz we are not allowed to buy next day -->
    }
    return dp[ind][buy] = profit;
}
int maxProfit(vector<int>& prices) {
    // int n = prices.size();
    // vector<vector<int>> dp(n, vector<int>(2, -1));
    // return bsswc(0, n, 1, prices, dp);
    int n = prices.size();
    vector<vector<int>> dp(n+2, vector<int>(2, 0));
    // n=0 done
    for(int ind=n-1; ind>=0; ind--){
        for(int buy=0; buy<=1; ++buy){
            int profit = 0;
            if(buy){
                profit = max(-prices[ind] + dp[ind+1][0], 0 + dp[ind+1][1]);
            }
            else{
                profit = max(+prices[ind] + dp[ind+2][1], 0 + dp[ind+1][0]);
            }
            dp[ind][buy]=profit;
        }
    }
    return dp[0][1];
}
