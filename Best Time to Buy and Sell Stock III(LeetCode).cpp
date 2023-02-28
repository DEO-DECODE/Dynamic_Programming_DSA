#include <bits/stdc++.h>
using namespace std;
// Best Time to Buy and Sell Stock III(LeetCode)
class Solution {
public:
int bss3(int ind, int n, int buy, int cap, vector<int> &prices, vector<vector<vector<int>>> dp)
{
    if (ind == n || cap == 0)
        return 0;
    if (dp[ind][buy][cap] != -1)
        return dp[ind][buy][cap];
    int profit = 0;
    if (buy == 1)
    {
        // Eligible to buy
        // We want to buy or we don't want to buy
        profit = max(-prices[ind] + bss3(ind + 1, n, 0, cap, prices, dp), 0 + bss3(ind + 1, n, 1, cap, prices, dp));
    }
    else
    {
        profit = max(+prices[ind] + bss3(ind + 1, n, 1, cap - 1, prices, dp), 0 + bss3(ind + 1, n, 0, cap, prices, dp));
        // A transactin will only be completed , if we sell the stock
    }
    return dp[ind][buy][cap] = profit;
}
int maxProfit(vector<int> &prices)
{
    // Recursive Approach
    int n = prices.size();
    // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
    // return bss3(0, n, 1, 3, prices, dp);
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
    for(int ind=n-1; ind>=0; --ind){
        for(int buy=1; buy>=0; buy--){
            for(int cap=1; cap<=2; ++cap){
                if(buy==1){
                    dp[ind][buy][cap]=max(-prices[ind]+dp[ind+1][0][cap], dp[ind+1][1][cap]);
                }
                else{
                    dp[ind][buy][cap]=max(+prices[ind]+dp[ind+1][1][cap-1], dp[ind+1][0][cap]);
                }
            }
        }
    }
    return dp[0][1][2];
}
};
