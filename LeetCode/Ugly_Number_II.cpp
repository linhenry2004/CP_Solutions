#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> nums;
        for (long i = 1; i <= INT_MAX; i *= 2) {
            for (long j = i; j <= INT_MAX; j *= 3) {
                for (long k = j; k <= INT_MAX; k *= 5) {
                    nums.push_back(k);
                }
            }
        }
        sort(nums.begin(), nums.end());
        return nums[n - 1];
    }
};