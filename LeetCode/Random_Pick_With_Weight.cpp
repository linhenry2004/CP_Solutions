#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    Solution(vector<int>& w) : vec(w) {
        for (int i = 1; i < vec.size(); i++) {
            vec[i] += vec[i - 1];
        }
    }
    
    int pickIndex() {
        return upper_bound(vec.begin(), vec.end(), rand()%vec.back()) - vec.begin();
    }

private: 
    vector<int>& vec;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */