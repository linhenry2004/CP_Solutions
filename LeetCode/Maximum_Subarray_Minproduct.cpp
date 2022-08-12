#include <bits/stdc++.h>
using namespace std;

#define ll long long
class Solution {
public:
    ll mod = 1e9 + 7;
    int maxSumMinProduct(vector<int>& nums) {
        ll ans = 0, n = nums.size();

        vector<ll> pre(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            pre[i] = pre[i - 1] + nums[i - 1];
        }

        vector<int> lef(n), rig(n);
        stack<int> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && (nums[s.top()] >= nums[i])) {
                s.pop();
            }
            if (s.empty()) {
                lef[i] = 0;
            } else {
                lef[i] = s.top() + 1;
            }
            s.push(i);
        }
        while (!s.empty()) {
            s.pop();
        }

        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && (nums[s.top()] >= nums[i])) {
                s.pop();
            }
            if (s.empty()) {
                rig[i] = n - 1;
            } else {
                rig[i] = s.top() - 1;
            }
            s.push(i);
        }
        for (int i = 0; i < n; i++) {
            ll sum = pre[rig[i] + 1] - pre[lef[i]];
            ans = max(ans, sum * nums[i]);
        }
        return ans % mod;
    }
};