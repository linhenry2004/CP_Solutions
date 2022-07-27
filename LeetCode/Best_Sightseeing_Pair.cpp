#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int res = 0, n = values.size(), mx = 0;
        
        for (int i = 0; i < n; i++) {
            res = max(res, mx + values[i] - i);
            mx = max(mx, values[i] + i);
        }
        return res;
    }
};