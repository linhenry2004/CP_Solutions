#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> x;
        for (int num : nums) {
            x.push_back(num);
        }
        for (int num : nums) {
            x.push_back(num);
        }
        return x;
    }
};