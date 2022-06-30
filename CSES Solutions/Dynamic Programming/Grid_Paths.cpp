#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define ll long long
const int modb = 1e9 + 7;

int main () {
    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    vector<vector<ll>> num(n, vector<ll> (n, 0));
    num[0][0] = (grid[0][0] == '.');
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] != '*') {
                if (i - 1 >= 0 && grid[i - 1][j] != '*') {
                    num[i][j] = (num[i][j] + num[i - 1][j]) % modb;
                }

                if (j - 1 >= 0 && grid[i][j - 1] != '*') {
                    num[i][j] = (num[i][j] + num[i][j - 1]) % modb;
                }
            }
        }
    }
    cout << num[n - 1][n - 1] << endl;
    return 0;
}