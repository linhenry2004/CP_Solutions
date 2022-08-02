#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        if (matrix.size() == 1) {
            return matrix[0][0];
        }
        int n = matrix.size(), res = INT_MAX;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int pre = matrix[i - 1][j];
                if (j > 0) {
                    pre = min(pre, matrix[i - 1][j - 1]);
                }
                if (j < n - 1) {
                    pre = min(pre, matrix[i - 1][j + 1]);
                }
                matrix[i][j] += pre;
                if (i == n - 1) {
                    res = min(res, matrix[i][j]);
                }
            }
        }
        return res;
    }
};