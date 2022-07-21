#include <bits/stdc++.h>
using namespace std;

class NumArray {
public:
    vector<int> sum;
    NumArray(vector<int>& nums) {
        sum.resize(nums.size());
        int s = 0;
        for (int i = 0; i < nums.size(); i++) {
            s += nums[i];
            sum[i] = s;
        }
    }
    
    int sumRange(int left, int right) {
        return left == 0 ? sum[right] : sum[right] - sum[left - 1];
    }
};