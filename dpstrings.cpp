#include <bits/stdc++.h>
using namespace std;
int lengthOfMaxSubstring(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();
    int maxsubstr = 0;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 0; i < m + 1; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 0; i < n + 1; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                maxsubstr = max(maxsubstr, dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    for (auto it : dp)
    {
        for (auto j : it)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return maxsubstr;
}

int lengthOfMaxSubsequence(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();
    int maxsubsequence = 0;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 0; i < n + 1; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i < m + 1; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    for (auto it : dp)
    {
        for (auto j : it)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    maxsubsequence = dp[n][m];
    return maxsubsequence;
}
int knapsack01(vector<int> weights, vector<int> value, int cap)
{
    int n = value.size();
    vector<vector<int>> dp(n + 1, vector<int>(cap + 1));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i < cap; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= cap; j++)
        {
            if (weights[i - 1] <= j)
            {
                dp[i][j] = max(dp[i - 1][j], value[i - 1] + dp[i - 1][j - weights[i - 1]]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    for (auto i : dp)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return dp[n][cap];
}

int main()
{
    string s1 = "abcdefg";
    string s2 = "abeg";
    cout << lengthOfMaxSubstring(s1, s2) << endl;
    // cout << lengthOfMaxSubsequence(s1, s2) << endl;
    // vector<int> profit = {1, 2, 5, 6};
    // vector<int> weight = {2, 3, 4, 5};
    // cout << knapsack01(weight, profit, 8) << endl;
    return 0;
}