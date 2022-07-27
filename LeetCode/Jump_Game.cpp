#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return false;
        }
        
        int mx = 0;
        for (int i = 0; i < n; i++) {
            if (i > mx) {
                return false;
            }
            if (mx > n) {
                return true;
            }
            mx = max(mx, nums[i] + i);
        }
        return true;
    }
}; 