#include <bits/stdc++.h>
using namespace std;
//Best Time to Buy and Sell Stock with Transaction Fee(LeetCode)
int maxProfit(vector<int> &prices, int fee)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    // n=0 done
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; ++buy)
        {
            int profit = 0;
            if (buy)
            {
                profit = max(-prices[ind] + dp[ind + 1][0], 0 + dp[ind + 1][1]);
            }
            else
            {
                profit = max(+prices[ind] - fee + dp[ind + 1][1], 0 + dp[ind + 1][0]);
            }
            dp[ind][buy] = profit;
        }
    }
    return dp[0][1];
}
