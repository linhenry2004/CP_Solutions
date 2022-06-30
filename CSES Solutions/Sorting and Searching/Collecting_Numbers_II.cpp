#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main () {
    int n, m;
    cin >> n >> m;
    vector<int> num(n + 1);
    vector<int> pos(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
        pos[num[i]] = i;
    }
    int count = 1;
    for (int j = 1; j < n; j++) {
        count += (pos[j] > pos[j + 1]);
    }

    int l, r;
    set<pair<int, int>> update;
    for (int i = 0; i < m; i++) {
        cin >> l >> r;

        if (num[l] + 1 <= n) {
            update.insert({num[l], num[l] + 1});
        }

        if (num[l] - 1 >= 1) {
            update.insert({num[l] - 1, num[l]});
        }

        if (num[r] + 1 <= n) {
            update.insert({num[r], num[r] + 1});
        }

        if (num[r] - 1 >= 1) {
            update.insert({num[r] - 1, num[r]});
        }

        for (pair<int, int> swap : update) {
            count -= (pos[swap.first] > pos[swap.second]);
        }

        swap(num[l], num[r]);
        pos[num[l]] = l;
        pos[num[r]] = r;

        for (pair<int, int> swap : update) {
            count += (pos[swap.first] > pos[swap.second]);
        }

        cout << count << endl;
        update.clear();
    }
    return 0;
}