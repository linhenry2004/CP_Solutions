#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

struct line {
    double a, b;

    line () {}
    line (double x, double y): a(x), b(y) {}

    double operator * (double x) {
        return a * x + b;
    }

    line operator ^ (line f) {
        double x, y;
        x = (b - f.b) / (f.a - a);
        y = f * x;
        return line(x, y);
    }
};

const int maxn = 2e5 + 1;
int l, r;
double F[maxn], S[maxn], dp[maxn];
line Q[maxn];

void pop (double x) {
    while (l < r && Q[l] * x > Q[l + 1] * x) {
        l++;
    }
}

void push (line f) {
    while (r > l) {
        auto [x, y] = f ^ Q[r - 1];
        if (Q[r] * x >= y) {
            r--;
        } else {
            break;
        }
    }
    Q[++r] = f;
}

int DP (int n, double x) {
    l = 0, r = -1;
    push({x, 0});
    for (int i = 1; i <= n; i++) {
        pop(S[i]);
        dp[i] = Q[l] * S[i];
        push({F[i], dp[i]});
    }
    return (int)dp[n];
}

int32_t main () {
    int n;
    double x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> S[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> F[i];
    }

    cout << DP(n, x) << endl;
    return 0;
}