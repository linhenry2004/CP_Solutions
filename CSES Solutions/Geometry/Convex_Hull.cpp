#include <bits/stdc++.h>
using namespace std;
#define int long long int

struct vec {
    int x, y;
    vec(){}
    vec (int x, int y): x(x), y(y) {}

    vec operator + (vec v) {
        return vec(x + v.x, y + v.y);
    }
    vec operator - (vec v) {
        return vec(x - v.x, y - v.y);
    }
    int operator * (vec v) {
        return x * v.x + y * v.y;
    }
    int operator ^ (vec v) {
        return x * v.y - y * v.x;
    }
};

const int maxn = 2e5 + 1;
vector<vec> V(maxn), S;

bool cmp (vec a, vec b) {
    return a.x == b.x ? a.y < b.y : a.x < b.x;
}

void print (vec v) {
    cout << v.x << " " << v.y << endl;
}

bool comp (vec a, vec b) {
    if (a ^ b) {
        return (a ^ b) > 0;
    } 
    return (a * b) > 0;
}

void hull (int n, int s) {
    vec a, b; 
    for (int i = 0; i < n; i++) {
        while (S.size() > s) {
            b = S.back();
            S.pop_back();
            a = S.back();
            if (comp(V[i] - a, b - a)) {
                S.push_back(b);
                break;
            }
        }
        S.push_back(V[i]);
    }
    S.pop_back();
}

int32_t main () {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        V[i] = vec(x, y);
    }
    sort(V.begin(), V.begin() + n, cmp);
    hull(n, 1);
    reverse(V.begin(), V.begin() + n);
    hull(n, S.size() + 1);
    cout << S.size() << endl;
    for (vec s : S) {
        print(s);
    }
    return 0;
}