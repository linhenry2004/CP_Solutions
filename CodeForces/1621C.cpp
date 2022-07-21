#include <bits/stdc++.h>
using namespace std;

int ask (int x) {
    cout << "? " << x + 1 << endl;
    int res;
    cin >> res;
    return res - 1;
}

int main () {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n, -1);
        for (int i = 0; i < n; i++) {
            if (a[i] == -1) {
                vector<int> cyc;
                int ans = ask(i);
                int x = ask(i);
                cyc.push_back(x);
                while (x != ans) {
                    x = ask(i);
                    cyc.push_back(x);
                }
                for (int j = 0; j < cyc.size(); j++) {
                    a[cyc[j]] = cyc[(j + 1) % cyc.size()];
                }
            }
        }

        cout << "! ";
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] + 1 << " ";
        }
        cout << endl;
    }
    return 0;
}