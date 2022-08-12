#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int squareSum (int n) {
        int sum = 0;
        while (n != 0) {
            int a = n % 10;
            sum += a * a;
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        if (n == 1 || n == 7) {
            return true;
        }
        while (n != 1) {
            if (n == 1 || n == 7) {
                return true;
            } else if (n > 1 && n <= 9) {
                return false;
            }
            n = squareSum(n);
        }
        return true;
    }
};