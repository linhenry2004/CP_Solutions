#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows > s.size()) {
            return s;
        }
        
        string sol;
        for (int i = 0; i < numRows; i++) {
            int x = i;
            sol.push_back(s[i]);
            while (true) {
                if (i != numRows - 1) {
                    x += 2 * (numRows - i - 1);
                    if (x >= s.size()) {
                        break;
                    }
                    sol.push_back(s[x]);
                }
                if (i != 0) {
                    x += 2 * i;
                    if (x >= s.size()) {
                        break;
                    }
                    sol.push_back(s[x]);
                }
            }
        }
        return sol;
    }
};