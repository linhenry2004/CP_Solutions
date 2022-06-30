#include <vector>
#include <assert.h>
#include <algorithm>
#include <iostream>
using namespace std;

int main () {
    int test_case;
    cin >> test_case;
    for (int i = 1; i <= test_case; i++) {
        cout << "Case #" << i << ": ";
        int n;
        cin >> n;
        vector <long long> F(n);

        for(int j = 0; j < n; j++) {
            cin >> F[j];
        }

        vector <int> P(n);
        vector <vector<int>> children(n);

        for (int j = 0; j < n; j++) {
            cin >> P[j];
            P[j]--;

            if (P[j] >= 0) {
                children[P[j]].push_back(j);
            }
        }

        long long total = 0;
        vector <long long> up(n, 0);

        for (int node = n - 1; node >= 0; node--) {
            vector <long long> sorted;

            for (int child : children[node]) {
                sorted.push_back(up[child]);
            }

            sort(sorted.begin(), sorted.end());

            while (sorted.size() > 1) {
                total += sorted.back();
                sorted.pop_back();
            }

            if (sorted.empty()) {
                sorted = {0};
            }

            assert(sorted.size() == 1);
            up[node] = max(sorted[0], F[node]);
        }

        for (int node = 0; node < n; node++) {
            if (P[node] < 0) {
                total += up[node];
            }
        }

        cout << total << endl;
    }
    return 0;
}