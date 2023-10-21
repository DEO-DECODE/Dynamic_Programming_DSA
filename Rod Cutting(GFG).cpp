//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
      int func(int ind, int w, vector<vector<int>> &dp, int price[])
  {
    if (ind == 0)
    {
      return w * price[0];
    }
    if (dp[ind][w] != -1)
      return dp[ind][w];
    int take = 0, notTake = 0;
    if (w >= ind + 1)
    {
      take = price[ind] + func(ind, w - (ind + 1), dp, price);
    }
    notTake = func(ind - 1, w, dp, price);
    return dp[ind][w] = max(take, notTake);
  }

  int cutRod(int price[], int n)
  {
    // code here
    vector<vector<int>> dp(n, vector<int> (n+1, -1));
    return func(n-1, n, dp, price);
  }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
