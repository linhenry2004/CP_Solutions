#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        int cu = 1;
        int ans = 0;
        vector<int> sq;
        while (cu * cu <= n) {
            sq.push_back(cu * cu);
            cu++;
        }
        int dp[n + 1];
        for (int i = 0; i < n + 1; i++) {
            dp[i] = 0;
        }
        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < sq.size(); j++) {
                if (i + sq[j] < n + 1) {
                    if (dp[i + sq[j]] == 0) {
                        dp[i + sq[j]] = dp[i] + 1;
                    } else {
                        dp[i + sq[j]] = min(dp[i] + 1, dp[i + sq[j]]);
                    }
                } else {
                    break;
                }
            }
        }
        return dp[n];
    }
};