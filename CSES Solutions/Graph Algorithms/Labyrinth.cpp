#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

int n, m;
bool vis[1001][1001];
char map[1001][1001];
char mov[1001][1001];
vector<vector<pair<int, int>>> par(1001, vector<pair<int, int>> (1001, make_pair(-1, -1)));

bool isValid (int x, int y) {
    if (x < 1 || x > n || y < 1 || y > m) {
        return false;
    }

    if (map[x][y] == '#' || vis[x][y] == true) {
        return false;
    }

    return true;
}

void bfs(int x, int y) {
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
            par[a][b - 1] = {a, b};
            mov[a][b - 1] = 'L';
        }

        if (isValid(a, b + 1)) {
            q.push({a, b + 1});
            vis[a][b + 1] = true;
            par[a][b + 1] = {a, b};
            mov[a][b + 1] = 'R';
        }

        if (isValid(a - 1, b)) {
            q.push({a - 1, b});
            vis[a - 1][b] = true;
            par[a - 1][b] = {a, b};
            mov[a - 1][b] = 'U';
        }

        if (isValid(a + 1, b)) {
            q.push({a + 1, b});
            vis[a + 1][b] = true;
            par[a + 1][b] = {a, b};
            mov[a + 1][b] = 'D';
        }

        if(q.empty() || map[a][b] == 'B') {
            break;
        }
    }
}

int main () {
    cin >> n >> m;
    int sr, sc, er, ec;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'A') {
                sr = i;
                sc = j;
            } else if (map[i][j] == 'B') {
                er = i;
                ec = j;
            }
        }
    }

    bfs(sr, sc);

    if (par[er][ec] == make_pair(-1, -1)) {
        cout << "NO" << endl;
        return 0;
    } else {
        cout << "YES" << endl;
    }

    int x = er;
    int y = ec;
    stack<char> stk;
    
    while (par[x][y] != make_pair(-1, -1)) {
        stk.push(mov[x][y]);
        int temp1 = par[x][y].first;
        int temp2 = par[x][y].second;
        x = temp1;
        y = temp2;
    }

    cout << stk.size() << endl;

    while (!stk.empty()) {
        cout << stk.top();
        stk.pop();
    }
    cout << endl;
    return 0;
}