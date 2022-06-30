#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 1;
int P[maxn], L[maxn];

void run (int n) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; i++) {
        if (!L[i]) {
            pq.push(i);
        }
    }
    for (int i = 1; i <= n - 2; i++) {
        cout << pq.top() << " " << P[i] << endl;
        pq.pop();
        if (i == L[P[i]]) {
            pq.push(P[i]);
        }
    }
    cout << pq.top() << " " << P[n - 2] << endl;
}

int32_t main () {
    int n;
    cin >> n;
    for (int i = 1; i <= n - 2; i++) {
        cin >> P[i];
        L[P[i]] = i;
    }
    L[P[n - 2]] = n;
    run(n);
    return 0;
}