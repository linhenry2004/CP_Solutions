#include <bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main () {
    int n, x, ans = 0;
    priority_queue<int> Q;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        Q.push(x);
        ans += Q.top() - x;
        Q.pop();
        Q.push(x);
    }
    cout << ans << endl;
    return 0;
}