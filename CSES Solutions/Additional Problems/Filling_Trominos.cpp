#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;
 
char tab [111][111];
char cols [5][5];
 
void set_colour(int x, int y, int dir) {
    char col = cols[x%4][y%4];
    if (dir == 0) {
        tab[x][y] = col;
        tab[x - 1][y] = col;
        tab[x][y + 1] = col;
    } else if (dir == 1) {
        tab[x][y] = col;
        tab[x - 1][y] = col;
        tab[x][y - 1] = col;
    } else if (dir == 2) {
        tab[x][y] = col;
        tab[x + 1][y] = col;
        tab[x][y - 1] = col;
    } else if (dir == 3) {
        tab[x][y] = col;
        tab[x + 1][y] = col;
        tab[x][y + 1] = col;
    }
}
 
void solve(int n1, int m1, int n2, int m2) {
    //cout << n1 << " " << m1 << " " << n2 << " " << m2 << "\n";
    if (n1 == 2) {
        for (int i = 0; i < m1/3; i++) {
             set_colour(n2, m2 + 3*i, 3);
             set_colour(n2 + 1, m2 + 3*i + 2, 1);
        }
    } else if (m1 == 2) {
        for (int i = 0; i < n1/3; i++) {
             set_colour(n2 + 3*i, m2, 3);
             set_colour(n2 + 3*i + 2, m2 + 1, 1);
         }
    } else if (n1 == 3) {
        for (int i = 0; i < m1/2; i++) {
            set_colour(n2, m2 + 2*i, 3);
            set_colour(n2 + 2, m2 + 2*i + 1, 1);
        }
    } else if (m1 == 3) {
        for (int i = 0; i < n1/2; i++) {
            set_colour(n2 + 2*i, m2, 3);
            set_colour(n2 + 2*i + 1, m2 + 2, 1);
        }
    } else if (n1 == 9) {
        set_colour(n2, m2, 3);
        set_colour(n2 + 1, m2 + 2, 0);
        set_colour(n2, m2 + 4, 2);
        set_colour(n2 + 2, m2 + 1, 1);
        set_colour(n2 + 3, m2 + 2, 0);
        set_colour(n2 + 2, m2 + 4, 2);
        set_colour(n2 + 3, m2, 3);
        set_colour(n2 + 4, m2 + 2, 2);
        set_colour(n2 + 4, m2 + 4, 2);
        set_colour(n2 + 5, m2, 3);
        set_colour(n2 + 6, m2 + 1, 3);
        set_colour(n2 + 6, m2 + 3, 0);
        set_colour(n2 + 8, m2, 0);
        set_colour(n2 + 7, m2 + 2, 3);
        set_colour(n2 + 8, m2 + 4, 1);
    } else if (m1 == 9) {
        set_colour(n2, m2, 3);
        set_colour(n2 + 2, m2 + 1, 2);
        set_colour(n2 + 4, m2, 0);
        set_colour(n2 + 1, m2 + 2, 1);
        set_colour(n2 + 2, m2 + 3, 2);
        set_colour(n2 + 4, m2 + 2, 0);
        set_colour(n2, m2 + 3, 3);
        set_colour(n2 + 2, m2 + 4, 0);
        set_colour(n2 + 4, m2 + 4, 0);
        set_colour(n2, m2 + 5, 3);
        set_colour(n2 + 1, m2 + 6, 3);
        set_colour(n2 + 3, m2 + 6, 2);
        set_colour(n2, m2 + 8, 2);
        set_colour(n2 + 2, m2 + 7, 3);
        set_colour(n2 + 4, m2 + 8, 1);
    }
}
 
void r_solve(int n1, int m1, int n2, int m2) {
    //cout << n1 << " " << m1 << " " << n2 << " " << m2 << "\n";
    if (n1 == 0) {
        return;
    }
    if (m1 == 0) {
        return;
    }
    if (n1 <= 3) {
        solve(n1, m1, n2, m2);
        return;
    }
    if (m1 <= 3) {
        solve(n1, m1, n2, m2);
        return;
    }
    if (n1 == 6) {
        if (m1%2 == 0) {
            solve(6, 2, n2, m2);
            r_solve(6, m1 - 2, n2, m2 + 2);
        } else {
            solve(6, 3, n2, m2);
            r_solve(6, m1 - 3, n2, m2 + 3);
        }
        return;
    }
    if (m1 == 6) {
        if (n1%2 == 0) {
            solve(2, 6, n2, m2);
            r_solve(n1 - 2, 6, n2 + 2, m2);
        } else {
            solve(3, 6, n2, m2);
            r_solve(n1 - 3, 6, n2 + 3, m2);
        }
        return;
    }
    if (n1 == 9) {
        if (m1%2 == 0) {
            solve(9, 2, n2, m2);
            r_solve(9, m1 - 2, n2, m2 + 2);
        } else {
            solve(9, 5, n2, m2);
            r_solve(9, m1 - 5, n2, m2 + 5);
        }
        return;
    }
    if (m1 == 9) {
        if (n1%2 == 0) {
            solve(2, 9, n2, m2);
            r_solve(n1 - 2, 9, n2 + 2, m2);
        } else {
            solve(5, 9, n2, m2);
            r_solve(n1 - 5, 9, n2 + 5, m2);
        }
        return;
    }
    if (n1%3 == 0) {
        r_solve(6, m1, n2, m2);
        r_solve(n1 - 6, m1, n2 + 6, m2);
        return;
    }
    if (m1%3 == 0) {
        r_solve(n1, 6, n2, m2);
        r_solve(n1, m1 - 6, n2, m2 + 6);
        return;
    }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        if (n == 1) {
            cout << "NO" << "\n";
            continue;
        }
        if (m == 1) {
            cout << "NO" << "\n";
            continue;
        }
        if (n == 2) {
            if (m % 3 != 0) {
                cout << "NO" << "\n";
                continue;
            }
        }
        if (m == 2) {
            if (n % 3 != 0) {
                cout << "NO" << "\n";
                continue;
            }
        }
        if (n == 3) {
            if (m % 2 != 0) {
                cout << "NO" << "\n";
                continue;
            }
        }
        if (m == 3) {
            if (n % 2 != 0) {
                cout << "NO" << "\n";
                continue;
            }
        }
        if (n*m%3 != 0) {
            cout << "NO" << "\n";
            continue;
        }
        cols[0][0] = 'A';
        cols[0][1] = 'B';
        cols[0][2] = 'C';
        cols[0][3] = 'D';
        cols[1][0] = 'E';
        cols[1][1] = 'F';
        cols[1][2] = 'G';
        cols[1][3] = 'H';
        cols[2][0] = 'I';
        cols[2][1] = 'J';
        cols[2][2] = 'K';
        cols[2][3] = 'L';
        cols[3][0] = 'M';
        cols[3][1] = 'N';
        cols[3][2] = 'O';
        cols[3][3] = 'P';
        r_solve(n, m, 0, 0);
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << tab[i][j];
            }
            cout << "\n";
        }
    }   
    return 0;
}