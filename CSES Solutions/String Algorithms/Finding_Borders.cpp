#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 1;
int Z[maxn];

int main () {
    string S;
    cin >> S;
    int l = 0, r = 0;
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
        }
    }

    for (int i = S.size() - 1; i > 0; i--) {
        if (Z[i] == S.size() - i) {
            cout << Z[i] << " ";
        }
    }
    cout << endl;
    return 0;
}