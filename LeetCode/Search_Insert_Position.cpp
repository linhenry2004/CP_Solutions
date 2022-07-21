#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return 0;
        }
        int l = 0, r = nums.size() - 1;
        int index = -1;
        while (l <= r) {
            index = (l + r) / 2;
            if (nums[index] == target) {
                return index;
            }
            if (nums[index] >= target) {
                r = index - 1;
            } else {
                l = index + 1;
            }
        }
        return l;
    }
};