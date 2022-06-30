#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 1;
int p = 1;
int pre[maxn], P[maxn];

void run (int l, int r) {
    int now = pre[p], mid = P[now];
    if (mid > l) {
        p++;
        run(l, mid - 1);
    }
    if (mid < r) {
        p++;
        run(mid + 1, r);
    }
    cout << now << " ";
}

int main () {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> pre[i];
    }
    int in;
    for (int i = 1; i <= n; i++) {
        cin >> in;
        P[in] = i;
    }
    run(1, n);
    cout << endl;
    return 0;
}