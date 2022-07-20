#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<long long, long long>

pii dp[15][15][25][15];
int num[25];

pii g (int sub, int f, int len, int pre) {
    num[len]++;
    if (dp[sub][f][len][pre].first!=-1) {
        return dp[sub][f][len][pre];
    }
    if (len == 0 || f == 0) {
        if (f == 0) {
            f = pre;
        }
        if (f == 0) {
            return{0, 0};
        } else if (sub <= f) {
            return {1, 0};
        } else {
            return {0, f};
        }
    }
    int nf = f, npre = pre;
    npre -= max(max(npre, sub), f);
    int sum = 1;
    if (npre == 0) {
        pii x = g(sub, f, len, 0);
        sum = x.first + 1;
        npre = x.second;
    } else {
        npre += 10;
        nf--;
        pii x;
        for (int i = 0; i < (len - 1); i++) {
            if (i != 0)  {
                x = g(9, 9, i, npre);
            } else {
                x = g(9, npre, i, npre);
            }
            sum += x.first;
            npre = x.second;
        }
        if(len >= 1){
            if (len>=2) {
                x=g(max(sub, nf), 9, len - 1, npre);
            } else {
                x = g(max(sub, nf), npre, len - 1, npre);
            }
            sum += x.first;
            npre = x.second;
        }
        x = g(sub, nf, len, npre);
        sum += x.first;
        npre = x.second;
    }
    return dp[sub][f][len][pre] = {sum,npre};
}

int solve (int n) {
    int a = n;
    string s = to_string(n);
    reverse(s.begin(), s.end());
    int pre = 0, res = 0;
    for (int i = 0; i < s.length(); i++) {
        int d = s[i] - '0', Max = 0;
        if (d == 0) {
            continue;
        }
        for (int j = s.length() - 1; j > i; j--) {
            Max = max(Max, (int)(s[j] - '0'));
        }
        pii x = g(Max, d, i, pre);
        pre = x.second;
        res += x.first;
    }
    return res;
}
int32_t main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, num = 0; 
    cin >> n;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            for (int p = 0; p < 20; p++) {
                for (int q = 0; q < 10; q++) {
                    dp[i][j][p][q] = {-1, 0};
                }
            }
        }
    }
    if (n == 1e18) {
        num = 1;
        n--;
    }
    cout << num + solve(n) << endl;
}