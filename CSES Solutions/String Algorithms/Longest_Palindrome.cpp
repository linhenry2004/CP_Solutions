#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e6 + 1;
int P[maxn];

string manacher (string T) {
    string S, A;
    int l = 0, r = 0, lng = 1, ans = 0;
    for (int i = 0; i <= 2 * T.size(); i++) {
        if(i & 1) {
            S += T[i / 2];
        } else {
            S += '#';
        }
    }

    P[0] = 1;
    for (int i = 1; i < S.size(); i++) {
        int mid = (l + r) / 2;
        P[i] = max(min(r - i, P[2 * mid - i]), 1);
        while (i >= P[i] && i + P[i] < S.size() && S[i - P[i]] == S[i + P[i]]) {
            l = i - P[i];
            r = i + P[i];
            P[i]++;
        }
        if (P[i] > lng || (P[i] == lng && i & 1)) {
            lng = P[i];
            ans = i;
        }
    }

    for (int i = ans - lng + 1; i < ans + lng; i++) {
        if(i & 1) {
            A += S[i];
        }
    }
    return A;
}

int main () {
    string T;
    cin >> T;
    cout << manacher(T) << endl;
    return 0;
}