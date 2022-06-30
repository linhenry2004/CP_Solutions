#include <bits/stdc++.h>
using namespace std;
#define int long long int

struct vec {
    int x, y;
    vec(){}
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

vec E[1001];

int area (int n) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += E[i] ^ E[i + 1];
    }
    return abs(ans);
}

int32_t main () {
    int n, x, y;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        E[i] = vec(x, y);
    }
    E[n] = E[0];
    cout << area(n) << endl;
    return 0;
}