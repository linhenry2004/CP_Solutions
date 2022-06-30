#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <stack>
#include <map>
using namespace std;

#define int long long int
#define max 1001

int n, m;
vector<pair<int, int>> monsters;
vector<vector<int>> g(max, vector<int> (max, INT_MAX));
pair<int, int> si, se;
map<pair<int, int>, pair<int, int>> par;
vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool isValid (int x, int y, int timer) {
    if (x < 0 || y < 0 || x >= n || y >= m) {
        return false;
    }

    if (g[x][y] <= timer) {
        return false;
    }

    return true;
}

bool isEscape (int x, int y, int timer) {
    if (!isValid(x, y, timer)) {
        return false;
    }
     
    if (x == 0 || y == 0 || x == n - 1 || y == m - 1) {
        return true;
    }

    return false;
}

bool bfs () {
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(si, 0));
    par[si] = {-1, -1};

    while (!q.empty()) {
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int timer = q.front().second;

        timer++;
        q.pop();

        for (auto mv : moves) {
            int tx = cx + mv.first;
            int ty = cy + mv.second;

            if (isEscape(tx, ty, timer)) {
                par[{tx, ty}] = {cx, cy};
                se = {tx, ty};
                return true;
            }

            if (isValid(tx, ty, timer)) {
                par[{tx, ty}] = {cx, cy};
                g[tx][ty] = timer;
                q.push({{tx, ty}, timer});
            }
        }
    }
    return false;
}

void preprocess () {
    queue <pair<pair<int, int>, int>> q;
    
    for (auto m : monsters) {
        q.push(make_pair(m, 0));
    }

    while (!q.empty()) {
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int timer = q.front().second;

        timer++;
        q.pop();

        for (auto mv : moves) {
            int tx = cx + mv.first;
            int ty = cy + mv.second;
            if (isValid(tx, ty, timer)) {
                g[tx][ty] = timer;
                q.push({{tx, ty}, timer});
            }
        }
    }
}

int32_t main () {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c; 
            cin >> c; 
            if (c == '#') {
                g[i][j] = 0;
            } else if (c == 'M') {
                g[i][j] = 0;
                monsters.push_back({i, j});
            } else if (c == 'A') {
                g[i][j] = 0;
                si = {i, j};
            }
        }
    }

    if (si.first == 0 || si.second == 0 || si.first == n - 1 || si.second == m - 1) {
        cout << "YES" << endl;
        cout << 0 << endl;
        return 0;
    }
    
    //Find out how long each block it will take for the monsters to arrive. 
    preprocess();

    if (!bfs()) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    pair<int, int> temp = se;
    pair<int, int> temp1 = par[se];
    pair<int, int> ed = {-1, -1};
    stack<char> ans;

    while (temp != ed) {
        if ((temp.second - temp1.second) == 1 && (temp.first - temp1.first) == 0) {
            ans.push('R');
        } 
        if ((temp.second - temp1.second) == -1 && (temp.first - temp1.first) == 0) {
            ans.push('L');
        }
        if ((temp.second - temp1.second) == 0 && (temp.first - temp1.first) == 1) {
            ans.push('D');
        }
        if ((temp.second - temp1.second) == 0 && (temp.first - temp1.first) == -1) {
            ans.push('U');
        }

        temp = par[temp];
        temp1 = par[temp];
    }

    cout << ans.size() << endl;

    while (!ans.empty()) {
        cout << ans.top();
        ans.pop();
    }

    cout << endl;
    return 0;
}