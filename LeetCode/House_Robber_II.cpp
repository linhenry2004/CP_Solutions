#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return nums[0];
        }
        
        vector<int> dp1(n), dp2(n);
        dp1[0] = nums[0], dp1[1] = max(dp1[0], nums[1]);
        for (int i = 2; i < n - 1; i++) {
            dp1[i] = max(dp1[i - 2] + nums[i], dp1[i - 1]);
        }
        
        dp2[0] = 0, dp2[1] = nums[1];
        for (int i = 2; i < n; i++) {
            dp2[i] = max(dp2[i - 2] + nums[i], dp2[i - 1]);
        }
        
        return max(dp1[n - 2], dp2[n - 1]);
    }
};