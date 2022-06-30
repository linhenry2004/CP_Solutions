#include <iostream>
#include <vector>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const int nax = 1e6 + 10;

int main () {
    vector<vector<ll>> num(nax, vector<ll> (8, 0));
    for (int i = 0; i < 8; i++) {
        num[0][i] = 1;
    }
    for (int i = 1; i < nax; i++) {
        for (int j = 0; j < 8; j++) {
            if (j == 0 || j == 2 || j == 3 || j == 4 || j == 5) {
                num[i][j] = (num[i - 1][0] + num[i - 1][1] + num[i - 1][3] + num[i - 1][4] + num[i - 1][5]) % mod;
            } else {
                num[i][j] = (num[i - 1][2] + num[i - 1][6] + num[i - 1][7]) % mod;
            }
        }
    }
    int t;
    cin >> t;
    for (int count = 0; count < t; count++) {
        int n;
        cin >> n;
        cout << (num[n - 1][2] + num[n - 1][6]) % mod << endl;
    }
    return 0;
}