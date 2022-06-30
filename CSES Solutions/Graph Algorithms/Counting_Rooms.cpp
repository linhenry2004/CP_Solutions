#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
bool vis[1001][1001];
char map[1001][1001];

bool isValid (int x, int y) {
    if (x < 1 || x > n || y < 1 || y > m) {
        return false;
    }

    if (map[x][y] == '#' || vis[x][y] == true) {
        return false;
    }

    return true;
}

void bfs (int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    vis[x][y] = true;

    while (true) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();

        if (isValid(a, b - 1)) {
            q.push({a, b - 1});
            vis[a][b - 1] = true;
        }

        if (isValid(a, b + 1)) {
            q.push({a, b + 1});
            vis[a][b + 1] = true;
        }

        if (isValid(a - 1, b)) {
            q.push({a - 1, b});
            vis[a - 1][b] = true;
        }

        if (isValid(a + 1, b)) {
            q.push({a + 1, b});
            vis[a + 1][b] = true;
        }

        if (q.empty()) {
            break;
        }
    }
}

int main () {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> map[i][j];
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (map[i][j] == '.' && vis[i][j] == false) {
                bfs(i, j);
                cnt++;
            }
        }
    }

    cout << cnt << endl;
    return 0;
}