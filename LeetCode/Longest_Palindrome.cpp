#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> mp;
        for (char c : s) {
            mp[c]++;
        }
        
        int ans = 0;
        for (auto v : mp) {
            ans += v.second / 2 * 2;
            if (ans % 2 == 0 && v.second % 2 == 1) {
                ans++;
            }
        }
        return ans;
    }
};