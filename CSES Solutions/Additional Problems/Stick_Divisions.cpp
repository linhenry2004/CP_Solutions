#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int maxn = 2e5 + 1;
int L[maxn];

int div (int n) {
    int a, b, sum = 0;
    priority_queue<int, vector<int>, greater<int>> Q;
    for (int i = 0; i < n; i++) {
        Q.push(L[i]);
    }
    while (Q.size() > 1) {
        a = Q.top(), Q.pop();
        b = Q.top(), Q.pop();
        sum += a + b;
        Q.push(a + b);
    }
    return sum;
}

int32_t main () {
    int x, n;
    cin >> x >> n;
    for (int i = 0; i < n; i++) {
        cin >> L[i];
    }
    cout << div(n) << endl;
    return 0;
}