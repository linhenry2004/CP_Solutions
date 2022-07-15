#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int maxn = 2e5 + 1;
bitset<maxn> pro, art, awy;
int X[maxn], Y[maxn];
vector<pair<int, int>> P, A;
priority_queue<int> sas;
priority_queue<int, vector<int>, greater<int>> bas;
priority_queue<pair<int, int>> de;

int chos (int a, int b) {
    int sum = 0, ans = 0;
    for (int i = 0; i < a + b; i++) {
        auto[x, j] = P[i];
        sum += Y[j];
        de.push({x - Y[j], j});
        art[j] = 1;
    }
    for (int i = a + b; i < P.size(); i++) {
        auto [x, j] = P[i];
        sas.push(Y[j]);
    }
    sas.push(0);
    while(de.size() > b) {
        auto [d, i] = de.top();
        de.pop();
        sum += d;
        pro[i] = 1;
        art[i] = 0;
    }
    ans = max(ans, sum);
    for (int i = a + b - 1; i >= a; i--) {
        auto [x, j] = P[i];
        awy[j] = 1;
        if (art[j]) {
            art[j] = 0;
            sum -= Y[j];
        } else {
            pro[j] = 0;
            sum -= x;
            while (awy[de.top().second]) {
                de.pop();
            }
            auto [d, k] = de.top();
            de.pop();
            sum += d;
            pro[k] = 1;
            art[k] = 0;
        }
        bas.push(Y[j]);
        sum += Y[j];
        if (sas.top() > bas.top()) {
            sum += sas.top() - bas.top();
            sas.push(bas.top());
            bas.push(sas.top());
            bas.pop(), sas.pop();
        }
        ans = max(ans, sum);
    }
    return ans;
}

int32_t main () {
    int a, b, n;
    cin >> a >> b >> n;
    for (int i = 1; i <= n; i++) {
        cin >> X[i] >> Y[i];
        P.push_back({X[i], i});
        A.push_back({Y[i], i});
    }
    sort(P.begin(), P.end(), greater<pair<int, int>> ());
    sort(A.begin(), A.end(), greater<pair<int, int>> ());
    cout << chos(a, b) << endl;
    return 0;
}