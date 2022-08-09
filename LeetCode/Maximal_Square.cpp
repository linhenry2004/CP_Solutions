#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>> &matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, -1));
        
        int res = 0;
        for (int i = rows; i >= 0; i--) {
            for (int j = cols; j >= 0; j--) {
                if (i == rows || j == cols || matrix[i][j] == '0') {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = 1 + min({dp[i][j + 1], dp[i + 1][j + 1], dp[i + 1][j]});
                }
                res = max(res, dp[i][j]);
            }
        }
        return res * res;
    }
};