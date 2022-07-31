#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int res = 0, cur = 0;
        int n = nums.size();
        for (int i = 2; i < n; i++) {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                cur++;
                res += cur;
            } else {
                cur = 0;
            }
        }
        return res;
    }
};