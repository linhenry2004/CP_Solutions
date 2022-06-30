#include <bits/stdc++.h>
using namespace std;
#define ll long long

int vis[8][8];
int di[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dj[8] = {2, 1, -1, -2, -2, -1, 1, 2};

bool free(int nx, int ny) {
    return nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && !vis[nx][ny];
}

int deg(pair<int, int> a) {
    int d = 0;
    for (int i = 0; i < 8; i++) {
        d += free(a.first + di[i], a.second + dj[i]);
    }
    return d;
}

void dfs (int x, int y, int a) {
    vis[x][y] = a + 1;
    if (a == 63) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                cout << vis[i][j] << " ";
            }
            cout << endl;
        }
        exit(0);
    }

    vector<pair<int, int>> p;
    for (int i = 0; i < 8; i++) {
        int nx = x + di[i], ny = y + dj[i];
        if (free(nx, ny)) {
            p.push_back({nx, ny});
        }
    }

    sort(p.begin(), p.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
        return deg(a) < deg(b);
    });

    for (pair<int, int> b : p) {
        dfs(b.first, b.second, a + 1);
    }

    vis[x][y] = 0;
}

int main () {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    swap(x, y);
    dfs(x, y, 0);
}