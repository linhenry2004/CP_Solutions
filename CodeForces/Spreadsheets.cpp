#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int n;
char a[N];

int main () {
    scanf("%d",&n);
    getchar();
    while (n--) {
        int x,y;
        gets(a);
        if (sscanf(a,"R%dC%d",&x,&y)==2) {
            int d[20],k = -1;
            while (y>0) {
                int t = y % 26;
                if (t) {
                    k++;
                    d[k] = t;
                    y /= 26;
                } else {
                    k++;
                    d[k] = 26;
                    y -= 26;
                    y /= 26;
                }
            }
            for (int i=k;i>=0;i--) {
                printf("%c",'A'-1+d[i]);
            }
            printf("%d\n",x);
        } else {
            int d[20], k = -1, x = 0, n = strlen(a);
            for (int i = 0; i < n; i++) {
                if (a[i] >= 'A' && a[i] <= 'Z') {
                    k++;
                    d[k] = a[i] - 'A' + 1;
                } else {
                    x = x * 10 + (a[i] - '0');
                }
            }
            int y = 0;
            for (int i = 0; i <= k; i++) {
                y = y * 26 + d[i];
            }
            printf("R%dC%d\n", x, y);
        }
    }
    return 0;
}