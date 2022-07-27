#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0, mx = 0, mn = 0, mx_sum = INT_MIN, mn_sum = INT_MAX;
        
        for (int x : nums) {
            total += x;
            mx = max(mx + x, x);
            mx_sum = max(mx, mx_sum);
            mn = min(mn + x, x);
            mn_sum = min(mn, mn_sum);
        }
        if (mx_sum > 0) {
            return max(mx_sum, total - mn_sum);
        }
        return mx_sum;
    }
};