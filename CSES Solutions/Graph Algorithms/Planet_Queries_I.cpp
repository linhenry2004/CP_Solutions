#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 2e5 + 1;
const int MAXD = 30; 
int n, q; 
int parent[MAXN][MAXD];

int32_t main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 1; i <= n; i++) {
        cin >> parent[i][0];
    }

    for(int d = 1; d < MAXD; d++) {
	    for(int i = 1; i <= n; i++) {
		    parent[i][d] = parent[parent[i][d - 1]][d - 1];
        }
	}

    for (int i = 0; i < q; i++) {
        int a, b; 
        cin >> a >> b; 
        for(int i = 0; i < MAXD; i++) {
            if(b & (1 << i)) {
                a = parent[a][i];
            }
        }
        cout << a << endl;
    }

    return 0;
}