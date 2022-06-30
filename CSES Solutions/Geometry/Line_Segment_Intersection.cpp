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

int cal (vec a, vec b, vec c, bool t) {
    int ans;
    if (t) {
        ans = (c - a) ^ (b - a);
    } else {
        ans = (c - a) * (b - a);
    }
    
    if (ans == 0) {
        return 0;
    } else if (ans > 0) {
        return 1;
    } else {
        return -1;
    }
}

bool line (vec a, vec b, vec c, vec d) {
    bool ans = 1;
    ans &= !cal(a, b, c, 1) && !cal(a, b, d, 1);
    ans &= (a - c) * (b - d) > 0 && (a - d) * (b - c) > 0;
    return ans;
}

bool inter (vec a, vec b, vec c, vec d) {
    bool ans = 1;
    ans &= cal(a, b, c, 1) * cal(a, b, d, 1) <= 0;
    ans &= cal(c, d, a, 1) * cal(c, d, b, 1) <= 0;
    ans &= !line(a, b, c, d);
    return ans;
}

int32_t main () {
    int t, x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> t;
    while (t--) {
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        cout << ((inter(vec(x1, y1), vec(x2, y2), vec(x3, y3), vec(x4, y4))) ? "YES" : "NO") << endl;
    }
    return 0;
}