#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;
        vector<int> result;
        for(int i = 0; i < nums.size(); i++) {
            if (mp.count(target - nums[i])) {
                result.push_back(i);
                result.push_back(mp[target - nums[i]]);
                return result;
            }
            mp.insert({nums[i], i});
        }
    }
};