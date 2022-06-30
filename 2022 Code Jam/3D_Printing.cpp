#include <vector>
#include <iostream>
#include <numeric>
using namespace std;

const int TARGET = 1e6;
const int INF = 1e9;

int main () {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int ink [3][4];
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 4; k++) {
                cin >> ink[j][k];
            }
        }

        vector<int> min_ink(4, INF);

        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 4; k++) {
                min_ink[k] = min(min_ink[k], ink[j][k]);
            }
        }

        int extra = accumulate(min_ink.begin(), min_ink.end(), 0) - TARGET;

        cout << "Case #" << i << ": ";
        if (extra < 0) {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }

        for (int j = 0; j < 4; j++) {
            int remove = min(extra, min_ink[j]);
            min_ink[j] -= remove;
            extra -= remove;
        }

        for(int it : min_ink) {
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}