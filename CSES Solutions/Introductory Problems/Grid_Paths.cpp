#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define ll long long

string str;
bool vis[7][7];
vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
// U, D, L, R

bool isValid (int a) {
    return a >= 0 && a < 7;
}

int countPaths (int x, int y, int pos) {
    if (pos == str.length()) {
        return (x == 6 && y == 0);
    }

    if (x == 6 && y == 0) {
        return 0;
    }

    //Check if unvisited portions are split
    // U = 0, D = 1, L = 2, R = 3
    vector<bool> visited(4, 1);
    for (int i = 0; i < 4; i++) {
        if (isValid(x + moves[i].first) && isValid(y + moves[i].second)) {
            visited[i] = vis[x + moves[i].first][y + moves[i].second];
        }
    }

    //Vertical and Horizontal
    if (!visited[0] && !visited[1] && visited[2] && visited[3]) {
        return 0;
    }
 
    if (visited[0] && visited[1] && !visited[2] && !visited[3]) {
        return 0;
    }

    //Diagonal
    if (isValid(x + 1) && isValid(y + 1) && vis[x + 1][y + 1]) {
        if (!visited[1] && !visited[3]) {
            return 0;
        }
    }

    if (isValid(x - 1) && isValid(y - 1) && vis[x - 1][y - 1]) {
        if (!visited[0] && !visited[2]) {
            return 0;
        }
    }

    if (isValid(x + 1) && isValid(y - 1) && vis[x + 1][y - 1]) {
        if (!visited[1] && !visited[2]) {
            return 0;
        }
    }

    if (isValid(x - 1) && isValid(y + 1) && vis[x - 1][y + 1]) {
        if (!visited[0] && !visited[3]) {
            return 0;
        }
    }

    //Brute Force
    vis[x][y] = true;
    int count = 0;
    if (str[pos] == '?') {
        for (auto move : moves) {
            if (isValid(x + move.first) && isValid(y + move.second) && !vis[x + move.first][y + move.second]) {
                count += countPaths(x + move.first, y + move.second, pos + 1);
            }
        }
    } else if (str[pos] == 'D' && !vis[x + 1][y] && x + 1 < 7) {
        count += countPaths(x + 1, y, pos + 1);
    } else if (str[pos] == 'U' && !vis[x - 1][y] && x - 1 >= 0) {
        count += countPaths(x - 1, y, pos + 1);
    } else if (str[pos] == 'R' && !vis[x][y + 1] && y + 1 < 7) {
        count += countPaths(x, y + 1, pos + 1);
    } else if (str[pos] == 'L' && !vis[x][y - 1] && y - 1 >= 0) {
        count += countPaths(x, y - 1, pos + 1);
    }
    vis[x][y] = false;
    return count;
}

int main () {
    cin >> str;
    cout << countPaths(0, 0, 0) << endl;
    return 0;
}