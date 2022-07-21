#include <bits/stdc++.h>
using namespace std;

struct pt {
    double x, y, r;
};

pt mkp (double x, double y) {
    pt ret;
    ret.x = x;
    ret.y = y;
    return ret;
};

double dis (pt a, pt b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double cost (pt *p, double x, double y) {
    double ang[3];
    for (int i = 0; i < 3; i++) {
        ang[i] = dis(p[i], mkp(x, y)) / p[i].r;
    }

    double diff[3];
    for (int i = 0; i < 3; i++) {
        diff[i] = ang[i] - ang[(i + 1) % 3];
    }

    double ret = 0;
    for (int i = 0; i < 3; i++) {
        ret += diff[i] * diff[i];
    }

    return ret;
}

const int dx[] = {0, 1, -1, 0};
const int dy[] = {1, 0, 0, -1};
const double err = 1e-6;

int main () {
    pt p[3];
    for (int i = 0; i < 3; i++) {
        scanf("%lf %lf %lf", &(p[i].x), &(p[i].y), &(p[i].r));
    }

    pt ans;
    ans.x = (p[0].x + p[1].x + p[2].x) / 3.0;
    ans.y = (p[0].y + p[1].y + p[2].y) / 3.0;
    double ncost = cost(p, ans.x, ans.y);

    pt tmp;
    double step = 1.0;
    bool flag = false;
    for (int i = 0; i < 300000 && ncost > err; i++) {
        flag = false;
        for (int k = 0; k < 4; k++) {
            tmp.x = ans.x + step * ((double) dx[k]);
            tmp.y = ans.y + step * ((double) dy[k]);

            if (ncost > cost(p, tmp.x, tmp.y)) {
                ncost = cost(p, tmp.x, tmp.y);
                ans = tmp;
                flag = true;
            }
        }
        if (!flag) {
            step *= 0.5;
        }
    }
    
    if (cost(p, ans.x, ans.y) <= err) {
        printf("%.5lf %.5lf\n", ans.x, ans.y);
    }
    return 0;
}