#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<string> symbol ({"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"});
        vector<int> numbers ({1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1});
        
        string res;
        for (int i = 0; i < numbers.size(); i++) {
            if (num >= numbers[i]) {
                for (int n = 0; n < (num / numbers[i]); n++) {
                    res += symbol[i];
                }
                num = num % numbers[i];
            }
        }
        
        return res;
    }
};