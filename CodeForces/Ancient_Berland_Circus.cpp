#include <bits/stdc++.h> 
using namespace std;

double x[3], y[3], l[3],ang[3],p,s,r,unita ;
const double PI = 3.1415926535;
const double ERR = 0.01;
 
bool feq (double a, double b) {
    return fabs(a-b) < ERR;
}
 
double fgcd(double a, double b) {
    if (feq(a, 0)) return b;
    if (feq(b, 0)) return a;
    return fgcd(b, fmod(a, b));
}
 
double dist(double x0, double x1, double y0, double y1) {
    return sqrt((x1-x0)*(x1-x0) + (y1-y0)*(y1-y0));
}
 
int main() {
 
 
    for (int i = 0; i < 3; i++)
        scanf("%lf %lf", &x[i], &y[i]);
 
 
    for (int i = 0; i < 3; i++)
        l[i] = dist(x[i], x[(i+1)%3], y[i], y[(i+1)%3]);
 
    p = (l[0] + l[1] + l[2]) / 2;
 
    s = sqrt(p * (p-l[0]) * (p-l[1]) * (p-l[2]));
 
    r = l[0] * l[1] * l[2] / (s * 4);
 
    for (int i = 0; i < 3; i++)
        ang[i] = acos(1 - l[i]*l[i] / (2 * r * r));
 
    ang[2] = 2 * PI - ang[0] - ang[1];
 
    unita = 0;
    for (int i = 0; i < 3; i++)
        unita = fgcd(unita, ang[i]);
 
    printf("%.6lf\n", r * r * sin(unita) * PI / unita);
    return 0;
}