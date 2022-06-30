#include <bits/stdc++.h>
using namespace std;
#define int long long int

struct line {
    int p, l, r;
};

const int INF = 1e6 + 1;
const int maxn = 2e6 + 1;
int BIT[maxn];
vector<line> A, Q;

bool cmp (line a, line b) {
    return a.p < b.p;
}

void update (int p, int x) {
    for (; p < maxn; p += p & -p) {
        BIT[p] += x;
    }
}

int query (int p) {
    int sum = 0;
    for (; p; p -= p & -p) {
        sum += BIT[p];
    }
    return sum;
}

int run () {
    int ans = 0, p = 0;
    for (auto [t, l, r] : Q) {
        while (p < A.size()) {
            auto [x, y, v] = A[p];
            if (x > t) {
                break;
            }
            update(y, v);
            p++;
        }
        ans += query(r) - query(l - 1);
    }
    return ans;
}

int32_t main () {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1 += INF, x2 += INF, y1 += INF, y2 += INF;
        if (x1 == x2) {
            Q.push_back({x1, y1, y2});
        } else {
            A.push_back({x1, y1, 1});
            A.push_back({x2 + 1, y2, -1});
        }
    }
    sort(Q.begin(), Q.end(), cmp);
    sort(A.begin(), A.end(), cmp);
    cout << run() << endl;
    return 0;
}