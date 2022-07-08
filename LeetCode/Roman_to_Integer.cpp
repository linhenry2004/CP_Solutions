#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> find  = {
            {'I', 1}, 
            {'V', 5}, 
            {'X', 10}, 
            {'L', 50}, 
            {'C', 100}, 
            {'D', 500}, 
            {'M', 1000},
        };
        
        int total = 0;
        int last = 0;
        int curr = 0;
        
        while (!s.empty()) {
            curr = find[s.back()];
            s.pop_back();
            
            if (curr >= last) {
                total += curr;
            } else {
                total -= curr;
            }
            last = curr;
        }
        
        return total;
    }
};