#include <bits/stdc++.h>
using namespace std;
// Edit Distance(LeetCode)
int f(string word1, string word2, int ind1, int ind2, vector<vector<int>> &dp)
{
    if (ind1 < 0)
        return ind2 + 1;
    /*
    Minimum operations to convert word1 which is empty to word2 of length (ind2+1) is ind2+1 by performing ind2+1 number of insertions.
    */
    if (ind2 < 0)
        return ind1 + 1;
    /*
     Minimum operations to convert word1 which is of length(ind1+1) to word2 which is an empty string is ind1+1 by performing ind1+1 number of deletions.
    */
    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];
    // Macth
    if (word1[ind1] == word2[ind2])
    {
        return dp[ind1][ind2] = f(word1, word2, ind1 - 1, ind2 - 1, dp);
    }
    // Not Match
    int deleting = 0, inserting = 0, replacing = 0;
    deleting = f(word1, word2, ind1 - 1, ind2, dp);
    inserting = f(word1, word2, ind1, ind2 - 1, dp);
    replacing = f(word1, word2, ind1 - 1, ind2 - 1, dp);
    return dp[ind1][ind2] = 1 + (min(inserting, min(deleting, replacing)));
}
int minDistance(string word1, string word2)
{
    int n1 = word1.size(), n2 = word2.size();
    vector<vector<int>> dp(n1, vector<int>(n2, -1));
    return f(word1, word2, n1 - 1, n2 - 1, dp);
}
