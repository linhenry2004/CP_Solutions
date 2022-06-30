#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    return (a.second < b.second);
}

int main () {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end(), cmp);

    set<pair<int, int>> s;
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (s.size() == 0) {
            s.insert({v[i].second * (-1), i});
        } else {
            auto t = s.lower_bound({v[i].first * (-1), -1});
            if (t != s.end()) {
                s.erase(t);
                s.insert({v[i].second * (-1), i});
            } else if (t == s.end() && s.size() < k) {
                s.insert({v[i].second * (-1), i});
            } else {
                count++;
            }
        }
    }

    cout << n - count << endl;
    return 0;
}