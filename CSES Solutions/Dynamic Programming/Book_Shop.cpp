#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

int main () {
    int n, x;
    cin >> n >> x;
    vector<int> price(n);
    vector<int> pages(n);
    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }

    vector<vector<int>> maxPages(n + 1, vector<int> (x + 1, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= x; j++) {
            maxPages[i + 1][j] = maxPages[i][j];
            if (j >= price[i]) {
                maxPages[i + 1][j] = max(maxPages[i + 1][j], pages[i] + maxPages[i][j - price[i]]);
            }
        }
    }
    cout << maxPages[n][x] << endl;
    return 0;
}