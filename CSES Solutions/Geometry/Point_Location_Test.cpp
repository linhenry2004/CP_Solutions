#include <bits/stdc++.h>
using namespace std;
#define int long long

struct vec {
    int x, y;
    vec (int x, int y): x(x), y(y) {}

    vec operator + (vec v) {
        return vec(x + v.x, y + v.y);
    }
    vec operator - (vec v) {
        return vec(x - v.x, y - v.y);
    }
    int operator * (vec v) {
        return x * v.x + y * v.y;
    }
    int operator ^ (vec v) {
        return x * v.y - y * v.x;
    }
};

int32_t main () {
    int t, x1, y1, x2, y2, x3, y3, ans;
    cin >> t;
    while (t--) {
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        ans = vec(x2 - x1, y2 - y1) ^ vec(x3 - x1, y3 - y1);
        if (ans > 0) {
            cout << "LEFT" << endl;
        } else if (ans < 0) {
            cout << "RIGHT" << endl;
        } else {
            cout << "TOUCH" << endl;
        }
    }
    return 0;
}