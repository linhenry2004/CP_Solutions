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

const vec inf = vec(1, 4e9);
vec V[1001];

int cal (vec a, vec b, vec c) {
    int ans;
    ans = (c - a) ^ (b - a);
    if (ans > 0) {
        return 1;
    } else if (ans < 0) {
        return -1;
    }
}

int inter (vec a, vec b, vec c, vec d) {
    // abc, abd, cda, cdb;
    int abc = cal(a, b, c);
    int abd = cal(a, b, d);
    int cda = cal(c, d, a);
    int cdb = cal(c, d, b);
    if (abc * abd < 0 && cda * cdb < 0) {
        return 1;
    } else {
        return 0;
    }
}

bool bound (vec a, vec b, vec c) {
    if(((a - b) ^ (c - b) || ((a - b)) * (c - b) > (c - b) * (c - b)) || ((a - b) * (c - b) < 0)) {
        return 0;
    } else {
        return 1;
    }
}

int in (vec p, int n) {
    int cnt = 0;
    bool on = 0;
    vec end = p + inf;
    for (int i = 0; i < n; i++) {
        cnt += inter(p, end, V[i], V[i + 1]);
        on |= bound(p, V[i], V[i + 1]);
    }

    if (on) {
        return 0;
    } else if (cnt & 1) {
        return 1;
    } else {
        return -1;
    }
}

int32_t main () {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        V[i] = vec(x, y);
    }
    V[n] = V[0];
    while (m--) {
        int x, y;
        cin >> x >> y;
        int ans = in(vec(x, y), n);
        if (ans > 0) {
            cout << "INSIDE" << endl;
        } else if (ans < 0) {
            cout << "OUTSIDE" << endl;
        } else {
            cout << "BOUNDARY" << endl;
        }
    }
    return 0;
}