#include <bits/stdc++.h>
using namespace std;

int C[128];
set<char> A;

string run (string &S) {
    int cnt = 0, n = S.size();
    char pre = '#', mos, now;
    string ans;

    for (char c = 'A'; c <= 'Z'; c++) {
        if (C[c] > cnt) {
            cnt = C[c];
            mos = c;
        }
    }

    while (2 * cnt <= n) {
        cnt = 0;
        if (pre == *A.begin()) {
            now = *++A.begin();
        } else {
            now = *A.begin();
        }
        C[now]--;
        ans += now;
        if (!C[now]) {
            A.erase(now);
        }
        for (char c = 'A'; c <= 'Z'; c++) {
            if (C[c] > cnt) {
                cnt = C[c];
                mos = c;
            }
        }
        pre = now;
        n--;
    }

    while (C[mos] > 1) {
        ans += mos;
        if (mos == *A.begin()) {
            now = *++A.begin();
        } else {
            now = *A.begin();
        }
        ans += now;
        C[now]--;
        C[mos]--;
        if (!C[now]) {
            A.erase(now);
        }
    }

    ans += mos;
    return ans;
}

int main () {
    int n, cnt = 0;
    string S;
    cin >> S;
    n = S.size();
    for (char s : S) {
        C[s]++;
        cnt = max(cnt, C[s]);
        A.insert(s);
    }
    if (cnt * 2 > n + (n & 1)) {
        cout << "-1" << endl;
        return 0;
    }
    cout << run(S) << endl;
    return 0;
}