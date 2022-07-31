#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int func (vector<int>& prices, int i, bool canBuy, vector<vector<int>> &dp) {
        if (i >= prices.size()) {
            return 0;
        }
        if (dp[i][canBuy] != -1) {
            return dp[i][canBuy];
        }
        int x, y;
        if (canBuy == 1) {
            x = func(prices, i + 1, 0, dp) - prices[i];
            y = func(prices, i + 1, 1, dp);
            return dp[i][canBuy] = max(x, y);
        } else {
            x = prices[i] + func(prices, i + 2, 1, dp);
            y = func(prices, i + 1, 0, dp);
            return dp[i][canBuy] = max(x, y);
        }
    }
    
    int maxProfit(vector<int>& prices) {
        int index = 0;
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return func(prices, index, 1, dp);
    }
};