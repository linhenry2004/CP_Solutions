#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 1;
int Z[maxn];

int main () {
    string S;
    cin >> S;
    int l = 0, r = 0;
    Z[0] = S.size();
    for (int i = 1; i < S.size(); i++) {
        if (i + Z[i - l] <= r) {
            Z[i] = Z[i - l];
        } else {
            l = i;
            if (i > r) {
                r = i;
            }
            while (r < S.size() && S[r] == S[r - l]) {
                r++;
            }
            r--;
            Z[i] = r - l + 1;
            if (Z[i] == S.size() - i) {
                cout << i << " ";
            }
        }
    }
    cout << S.size() << endl;
    return 0;
}