#include <bits/stdc++.h>
using namespace std;
#define int long long
 
 
int dp[100005][3];
 
int f (int pos, int id, vector<vector<int>> &points) {
    if (id < 0) {
        return 0;
    }
    if (dp[id][pos] != -1) {
        return dp[id][pos];
    }

    int take, notTake;
    
    if (pos == 0) {
        take = points[id][1] + f(1, id - 1, points);
        notTake = points[id][2] + f(2, id - 1, points);
    } else if (pos == 1) {
        take = points[id][0] + f(0, id - 1, points);
        notTake = points[id][2] + f(2, id - 1, points);
    } else {
        take = points[id][1] + f(1, id - 1, points);
        notTake = points[id][0] + f(0, id - 1, points);
    }
    
    return dp[id][pos] = max(take,notTake);
}
 
int res (int n, vector<vector<int>> &points) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            dp[i][j] = -1;
        }
    }
    
    int a = points[n - 1][0] + f(0, n - 2, points);
    int b = points[n - 1][1] + f(1, n - 2, points);
    int c = points[n - 1][2] + f(2, n - 2, points);
 
    int d = max(a, b);
    return(max(c, d));
}

int32_t main () {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    int tt = 1;
    
    while (tt--) {
        int n;
        cin >> n;
        
        vector<vector<int>> p;
        for(int i = 0; i < n; i++){
            int a, b, c;
            cin >> a >> b >> c;
            p.push_back({a, b, c});
        }
        cout << res(n, p);
    }
}