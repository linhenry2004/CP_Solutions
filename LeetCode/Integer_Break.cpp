#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ans;
    int integerBreak(int n) {
        vector<int> dp(n + 1, -1);
        dp[0] = dp[1] = 1;
        return calc(n, true, dp);
    }
    int calc (int n, bool flag, vector<int> &dp) {
        if (dp[n] != -1) {
            return dp[n];
        } else {
            int i = n;
            if (flag) {
                i = n - 1;
            }
            int p = 0;
            while (i >= 1) {
                p = max(p, i * calc(n - i, false, dp));
                i--;
            }
            return dp[n] = p;
        }
    }
};