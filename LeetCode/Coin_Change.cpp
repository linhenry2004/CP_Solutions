#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX - 1);
        
        dp[0] = 0;
        for (auto coin : coins) {
            if (coin <= amount) {
                dp[coin] = 1;
            }
        }
        if (dp[amount] == 1) {
            return 1;
        }
        
        for (int i = 1; i <= amount; i++) {
            for (auto coin : coins) {
                if (coin <= i) {
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
                }
            }
        }
        
        if (dp[amount] == INT_MAX - 1) {
            return -1;
        } else {
            return dp[amount];
        }
    }
};