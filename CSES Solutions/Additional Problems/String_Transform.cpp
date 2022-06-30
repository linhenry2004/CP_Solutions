#include <bits/stdc++.h>
using namespace std;

const int maxn = 128;
vector<char> C[maxn];
vector<int> I[maxn];
int P[maxn];

string trans (string &S) {
    int p = 0;
    char now = '#', tmp;
    string ans;
    for (char s : S) {
        C[s].push_back(s);
        I[s].push_back(0);
    }
    for (int i = 0; i < maxn; i++) {
        for (int j = 0; j < C[i].size(); j++) {
            C[i][j] = S[p];
            I[i][j] = P[S[p++]]++;
        }
    }

    p = 0;
    for (int i = 1; i < S.size(); i++) {
        tmp = now;
        now = C[now][p];
        p = I[tmp][p];
        ans += now;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main () {
    string S;
    cin >> S;
    cout << trans(S) << endl;
    return 0;
}