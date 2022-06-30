#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int maxn = 2e5 + 1;
array<array<int, 26>, maxn> P;;

void build (string &S) {
    set<int> M;
    int p = 1;
    for (char s : S) {
        for (int i = 0; i < 26; i++) {
            P[p][i] = P[p - 1][i];
        }
        P[p++][s - 'a']++;
        M.insert(s - 'a');
    }
    for (int i = 1; i <= S.size(); i++) {
        for (int j = 25; j >= 0; j--) {
            if (M.find(j) == M.end()) {
                continue;
            }
            P[i][j] -= P[i][0];
        }
    }
}

int run (string &S) {
    int ans = 0;
    map<array<int, 26>, int> M;
    for (int i = 0; i <= S.size(); i++) {
        ans += M[P[i]];
        M[P[i]]++;
    }
    return ans;
}

int32_t main () {
    string S;
    cin >> S;
    build(S);
    cout << run(S) << endl;
    return 0;
}