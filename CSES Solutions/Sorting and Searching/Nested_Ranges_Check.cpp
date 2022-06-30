#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct range {
    int l;
    int r;
    int index;

    bool operator < (const range &other) const {
        if (l == other.l) {
            return r > other.r;
        }

        return l < other.l;
    }
};

int main () {
    int n;
    cin >> n;

    vector<range> ranges(n);
    for (int i = 0; i < n; i++) {
        cin >> ranges[i].l >> ranges[i].r;
        ranges[i].index = i;
    }
    sort(ranges.begin(), ranges.end());

    vector<bool> contained(n);
    int maxEnd = 0;
    for (int i = 0; i < n; i++) {
        if (ranges[i].r <= maxEnd) {
            contained[ranges[i].index] = true;
        }
        maxEnd = max(maxEnd, ranges[i].r);
    }

    vector<bool> contains(n);
    int minEnd = 1e9 + 1;
    for (int i = n - 1; i >= 0; i--) {
        if (ranges[i].r >= minEnd) {
            contains[ranges[i].index] = true;
        }
        minEnd = min(minEnd, ranges[i].r);
    }

    for (auto c : contains) {
        cout << c << " ";
    }
    cout << endl;

    for (auto c : contained) {
        cout << c << " ";
    }
    cout << endl;
    return 0;
}