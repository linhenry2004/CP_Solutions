#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int curr = 0, i = 0, n = nums.size(), lvl = 0;
        
        while (curr < n - 1) {
            lvl++;
            int pre = curr;
            for (; i <= pre; i++) {
                curr = max(curr, i + nums[i]);
            }
        }
        return lvl;
    }
};