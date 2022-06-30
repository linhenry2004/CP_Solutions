#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 1;
int cnt[maxn];

int gcd () {
    int div;
    for (int i = 1e6; i > 0; i--) {
        div = 0;
        for (int j = i; j <= 1e6; j += i) {
            div += cnt[j];
        }
        if (div > 1) return i;
    }
}

int main () {
    int n, x;
    cin >> n;
    while (n--) {
        cin >> x;
        cnt[x]++;
    }
    cout << gcd() << endl;
    return 0;
}