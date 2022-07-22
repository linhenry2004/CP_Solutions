#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct cmp {
        bool operator() (const pair<int, string> &a, const pair<int, string> &b) {
            if (a.first != b.first) {
                return a.first > b.first;
            } else {
                return a.second < b.second;
            }
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for (int i = 0; i < words.size(); i++) {
            mp[words[i]]++;
        }
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq;
        for (auto i = mp.begin(); i != mp.end(); i++) {
            pq.push({i->second, i->first});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        
        vector<string> freq;
        while (pq.size() > 0) {
            freq.push_back(pq.top().second);
            pq.pop();
        }
        reverse(freq.begin(), freq.end());
        return freq;
    }
};