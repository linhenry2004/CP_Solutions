#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void expand (string s, int l, int r, int &bestleft, int &bestright) {
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            l--;
            r++;
        }
        l++;
        r--;
        if (r - l + 1 > bestright - bestleft + 1) {
            bestleft = l;
            bestright = r;
        }
    }
    string longestPalindrome(string s) {
        int bestleft = 0;
        int bestright = 0;
        
        for (int i = 0; i < s.size(); i++) {
            expand(s, i, i, bestleft, bestright);
            expand(s, i, i + 1, bestleft, bestright);
        }
        return s.substr(bestleft, bestright - bestleft + 1);
    }
};