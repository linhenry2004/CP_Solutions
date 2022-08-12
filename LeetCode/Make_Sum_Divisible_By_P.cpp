#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int ans = nums.size();
        int remove_sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            remove_sum = (remove_sum + nums[i]) % p;
        }
        if (remove_sum == 0) {
            return 0;
        }
        unordered_map<int, int> mp;
        mp[0] = -1;
        int curr = 0;
        for (int i = 0; i < nums.size(); i++) {
            curr = (curr + nums[i]) % p;
            mp[curr] = i;
            int rem = (curr - remove_sum + p) % p;
            if (mp.find(rem) != mp.end()) {
                ans = min(ans, i - mp[rem]);
            }
        }
        return ans >= nums.size() ? -1 : ans;
    }
};