#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() == 0) {
            return 0;
        }
        
        int count = 0;
        unordered_map<int, int> mp;
        int currsum = 0;
        
        for (int n : nums) {
            currsum += n;
            if (currsum == k) {
                count++;
            }
            if (mp.find(currsum - k) != mp.end()) {
                count += mp[currsum - k];
            }
            if (mp.find(currsum) != mp.end()) {
                mp[currsum]++;
            } else {
                mp[currsum] = 1;
            }
        }
        return count;
    }
};