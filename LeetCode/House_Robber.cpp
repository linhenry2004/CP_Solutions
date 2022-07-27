#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        
        int n = nums.size();
        int rob[n];
        rob[0] = nums[0];
        rob[1] = max(nums[0], nums[1]);
        
        for (int i = 2; i < n; i++) {
            rob[i] = max(rob[i - 1], rob[i - 2] + nums[i]);
        }
        return rob[n - 1];
    }
};