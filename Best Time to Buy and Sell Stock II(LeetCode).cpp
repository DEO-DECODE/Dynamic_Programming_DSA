#include <bits/stdc++.h>
using namespace std;
// Best Time to Buy and Sell Stock II(LeetCode)
int f(vector<int> &prices, int ind, vector<vector<int>> &dp, int buy)
{
    if (ind >= prices.size())
        return 0;
    if (dp[ind][buy] != -1)
        return dp[ind][buy];
    // Case of Buy.
    long long int profit = 0;
    if (buy == 0)
    {
        profit = max(0 + f(prices, ind + 1, dp, 0), prices[ind] + f(prices, ind + 1, dp, 1));
    }
    else
    {
        profit = max(0 + f(prices, ind + 1, dp, 1), -prices[ind] + f(prices, ind + 1, dp, 0));
    }
    return dp[ind][buy] = profit;
}
int maxProfit(vector<int> &prices)
{
    // Recursive Approach.
    int n = prices.size();
    // vector<vector<int>> dp(n, vector<int>(2, -1));
    // return f(prices, 0, dp, 1);
    // Tabulation Approach.
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    for (int ind = n - 1; ind >= 0; --ind)
    {
        for (int buy = 1; buy >= 0; --buy)
        {
            int profit = 0;
            if (buy)
            {
                profit = max(dp[ind + 1][1], -prices[ind] + dp[ind + 1][0]);
            }
            else
            {
                profit = max(dp[ind + 1][0], +prices[ind] + dp[ind + 1][1]);
            }
            dp[ind][buy] = profit;
        }
    }
    return dp[0][1];
}
