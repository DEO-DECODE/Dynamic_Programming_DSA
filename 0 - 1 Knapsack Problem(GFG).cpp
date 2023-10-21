//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
      int func(int ind, int w, vector<vector<int>> &dp, int wt[], int val[])
  {
    if (ind == 0)
    {
      if (w >= wt[ind])
      {
        return val[ind];
      }
      else
        return 0;
    }
    if (dp[ind][w] != -1)
      return dp[ind][w];
    int take = 0, notTake = 0;
    if (w >= wt[ind])
    {
      take = val[ind] + func(ind - 1, w - wt[ind], dp, wt, val);
    }
    notTake = func(ind - 1, w, dp, wt, val);
    return dp[ind][w] = max(take, notTake);
  }

  int knapSack(int W, int wt[], int val[], int n)
  {
    // Your code here
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    return func(n - 1, W, dp, wt, val);
  }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends
