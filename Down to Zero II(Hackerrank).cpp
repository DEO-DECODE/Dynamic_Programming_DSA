#include <bits/stdc++.h>
using namespace std;
int ans = 1e5;
int numStepsToZero(int n, vector<int> &dp)
{
	if (n == 0)
		return 0;

	if (dp[n] != -1)
		return dp[n];

	int minm = INT_MAX;
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
			minm = min(minm, 1 + numStepsToZero(max(n / i, i), dp));
	}

	return dp[n] = min(minm, 1 + numStepsToZero(n - 1, dp));
}

int main()
{
	int q;
	cin >> q;
	vector<int> dp(1e6, -1);
	while (q--)
	{
		int n;
		cin >> n;
		if (dp[n] != -1)
		{
			cout << dp[n] << endl;
		}
		else
		{
			cout<<numStepsToZero(n, dp)<<endl;
		}
	}
}
