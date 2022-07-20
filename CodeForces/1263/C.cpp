#include <bits/stdc++.h>
using namespace std;

int t, n;
void f () {
    vector<int> q;
    int r = 1;
    while (true) {
        q.push_back(n / r);
        if (q.back() == 0) {
            break;
        }
        r = (n / q.back() + 1);
    }
    cout << q.size() << endl;
    for (int i = q.size() - 1; i >= 0; i--) {
        cout << q[i] << " ";
    }
    cout << endl;
}

int main () {
    cin >> t;
    while (t--) {
        cin >> n;
        f();
    }
    return 0;
}