class Solution {
public:
static bool cmp(string &a, string &b)
{
    return a.size() < b.size();
}
static bool isPred(string &a, string &b)
{
  if(b.size()!=a.size()+1) return false;
  // b baad wala hai and a pehle ka
  int ind1 = 0, ind2 = 0;
  while (ind2 < b.size())
  {
    if (ind2<b.size()&&a[ind1]==b[ind2])
    {
      ind1++;
      ind2++;
    }
    else
    {
      ind2++;
    }
  }
  return ind1 == a.size() && ind2 == b.size();
}
int longestStrChain(vector<string> &words)
{
  int n = words.size();
  vector<int> dp(n, 1);
  int maxm = 1;
  sort(words.begin(), words.end(), cmp);
  for (int i = 0; i < n; ++i)
  {
    for (int prev = 0; prev < i; ++prev)
    {
      if (isPred(words[prev], words[i])&& 1 + dp[prev] > dp[i])
      {
        dp[i] = 1 + dp[prev];
      }
    }
    maxm = max(maxm, dp[i]);
  }
  return maxm;
}
};
