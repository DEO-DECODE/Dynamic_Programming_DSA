#include <bits/stdc++.h>
using namespace std;
// Best Time to Buy and Sell Stock(LeetCode)

int maxProfit(vector<int> &prices)
{
    int buy = prices[0], ans=0;
    int n = prices.size();
    for (int i = 1; i < n; ++i)
    {
        if(ans<prices[i]-buy){
            ans=prices[i]-buy;
        }
        buy=min(buy, prices[i]);
    }
    return ans;
}
