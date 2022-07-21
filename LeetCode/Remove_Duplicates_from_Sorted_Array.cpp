#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return 1;
        }
        int i = 0, k = 1, count = 1;
        while (k < nums.size()) {
            if (nums[k] <= nums[i]) {
                k++;
                continue;
            } else {
                i++;
                nums[i] = nums[k];
                count++;
            }
        }
        return count;
    }
};