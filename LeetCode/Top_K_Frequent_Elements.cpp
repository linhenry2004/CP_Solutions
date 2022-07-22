#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>> pq;
        vector<int> res;
        
        for (auto num : nums) {
            mp[num]++;
        }
        for (auto it : mp) {
            pq.push({it.second, it.first});
        }
        while (k--) {
            res.push_back(pq.top().second); 
            pq.pop();
        }
        return res;
    }
};