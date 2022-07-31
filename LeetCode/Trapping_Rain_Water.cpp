#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        const int n = height.size();
        vector<int> l(n);
        vector<int> r(n);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            l[i] = i == 0 ? height[i] : max(l[i - 1], height[i]);
        }
        for (int i = n - 1; i >= 0; i--) {
            r[i] = i == n - 1 ? height[i] : max(r[i + 1], height[i]);
        }
        for (int i = 0; i < n; i++) {
            ans += min(l[i], r[i]) - height[i];
        }
        return ans;
    }
};