#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int res = 0, plen = 0, nlen = 0;
        for (auto num : nums) {
            if (num == 0) {
                plen = 0, nlen = 0;
            } else if (num > 0) {
                plen += 1;
                nlen = nlen > 0 ? nlen + 1 : 0;
            } else {
                int tmp = nlen;
                nlen = plen + 1;
                plen = tmp > 0 ? tmp + 1 : 0;
            }
            res = max(res, plen);
        }
        return res;
    }
};