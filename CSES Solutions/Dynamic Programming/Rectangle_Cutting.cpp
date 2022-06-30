#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int INF = 1e9;
const int mx = 505;

int32_t main () {
    int width, height;
    cin >> width >> height;

    vector<vector<int>> cut (width + 1, vector<int> (height + 1, INF));

    for (int w = 1; w <= width; w++) {
        for (int h = 1; h <= height; h++) {
            if (w == h) {
                cut[w][h] = 0;
            } else {
                for (int c = 1; c < w; c++) {
                    cut[w][h] = min(cut[w][h], cut[c][h] + cut[w - c][h] + 1);
                }

                for (int c = 1; c < h; c++) {
                    cut[w][h] = min(cut[w][h], cut[w][c] + cut[w][h - c] + 1);
                }
            }
        }
    }

    cout << cut[width][height] << endl;
    return 0;
}