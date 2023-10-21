//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
      int mod = 1e9 + 7;
  int helper(vector<int> &arr, int target, int n, vector<vector<int>> &dp)
  {
    if (n == 0)
      return target == 0;
    if (dp[target][n] != -1)
      return dp[target][n];
    int take = 0, notTake = 0;
    if (arr[n - 1] <= target)
      take = (helper(arr, target - arr[n - 1], n - 1, dp) % mod);
    notTake = helper(arr, target, n - 1, dp) % mod;
    return dp[target][n] = (take + notTake) % mod;
  }
  int countPartitions(int n, int d, vector<int> &arr)
  {
    // Code here
    int sum = accumulate(arr.begin(), arr.end(), 0);
    if ((sum + d) % 2)
      return 0;
    int target = ((sum + d) / 2) % mod;
    vector<vector<int>> dp(target + 1, vector<int>(n + 1, -1));
    return helper(arr, target, n, dp) % mod;
  }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends
