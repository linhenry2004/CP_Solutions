#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        
        int l = 0, r = 0, sum = 0, n = nums.size(), res = n + 1;
        while (r< n) {
            while (sum < target && r < n) {
                sum += nums[r++];
            }
            while (sum >= target) {
                res = min(res, r - l);
                sum -= nums[l++];
            }
        }
        return res == n + 1 ? 0 : res;
    }
};