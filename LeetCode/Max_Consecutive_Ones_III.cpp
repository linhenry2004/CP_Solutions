#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        queue<int> q;
        int n = nums.size(), ans = 0;
        q.push(-1);
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (q.size() > k) {
                    ans = max(ans, i - q.front() - 1);
                    q.pop();
                } else {
                    ans = max(ans, i - q.front());
                }
                q.push(i);
            }
        }
        ans = max(ans, n - q.front() - 1);
        return ans;
    }
};
