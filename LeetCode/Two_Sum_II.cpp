#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        vector<int> result;
        while (1) {
            int ans = numbers[l] + numbers[r];
            if (ans == target) {
                result.push_back(l + 1);
                result.push_back(r + 1);
                return result;
            }
            if (ans > target) {
                r--;
            }
            if (ans < target) {
                l++;
            }
        }
    }
};