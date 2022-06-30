#include <bits/stdc++.h>
using namespace std;

int F[1004][1004], BIT[1004][1004];

void update(int x, int y, int v){
    for(int i = x; i < 1004; i += i & -i){
        for(int j = y; j < 1004; j += j & -j){
            BIT[i][j] += v;
        }
    }
}

int query (int x, int y) {
    int sum = 0;
    for(int i = x; i > 0; i -= i & -i){
        for(int j = y; j > 0; j -= j & -j){
            sum += BIT[i][j];
        }
    }
    return sum;
}

int32_t main () {
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char f;
            cin >> f;
            if (f == '*') {
                update(i, j, 1);
                F[i][j] = 1;
            } else {
                F[i][j] = 0;
            }
        }
    }

    while (q--) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1) {
            if(F[x][y]) update(x, y, -1);
            else update(x, y, 1);
            F[x][y] ^= 1;
        } else {
            int x1, y1;
            cin >> x1 >> y1;
            cout << query(x1, y1) - query(x1, y - 1) - query(x - 1, y1) + query(x - 1, y - 1) << endl;
        }
    }
    return 0;
}