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

const int maxn = 1e5 + 1;
vec V[maxn];

int gcd (int a, int b) {
    return b ? gcd(b, a % b) : a;
}

pair<int, int> point (int n) {
    int area = 0, on = 0, in;
    vec tmp;
    for (int i = 0; i < n; i++) {
        tmp = V[i] - V[i + 1];
        area += V[i] ^ V[i + 1];
        on += gcd(abs(tmp.x), abs(tmp.y));
    }
    area = abs(area);
    in = (area - on + 2) / 2;
    return {in, on};
}

int32_t main () {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        V[i] = vec(x, y);
    }
    V[n] = V[0];
    pair<int, int> ans = point(n);
    cout << ans.first << " " << ans.second << endl;
    return 0;
}