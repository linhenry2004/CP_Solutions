#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 1;
int bit[maxn], s[maxn];

void update(int p, int x) {
    for (; p < maxn; p += p & -p) {
        bit[p] += x;
    }
}

int find (int x) {
    int sum = 0, p = 0;
    for (int i = 17; i >= 0; i--) {
        if (p + (1 << i) < maxn && sum + bit[p + (1 << i)] < x) {
            p += (1 << i);
            sum += bit[p];
        }
    }
    return p + 1;
}

int main () {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        update(i, 1);
    }

    while (n--) {
        int p;
        cin >> p;
        int index = find(p);
        cout << s[index] << " ";
        update(index, -1);
    }
    cout << endl;
    return 0;
}