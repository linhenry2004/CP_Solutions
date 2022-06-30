#include <bits/stdc++.h>
using namespace std;

int main () {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ans = 0;
        while (n--) {
            int x;
            cin >> x;
            ans ^= (x % 4);
        }
        cout << (ans ? "first" : "second") << endl;
    }
    return 0;
}