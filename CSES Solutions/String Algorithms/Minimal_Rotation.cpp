#include <bits/stdc++.h>
using namespace std;

string LMS (string S) {
    int n = S.size(), i = 0, j = 1, k;
    S += S;
    while (i < n && j < n) {
        k = 0;
        while (S[i + k] == S[j + k]) {
            k++;
        }
        if (S[i + k] <= S[j + k]) {
            j += k + 1;
        } else {
            i += k + 1;
        }
        if (i == j) {
            j++;
        }
    }
    i = (i < n) ? i : j;
    return S.substr(i, n);
}

int main () {
    string S;
    cin >> S;
    cout << LMS(S) << endl;
    return 0;
}