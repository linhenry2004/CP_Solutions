#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define mid ((l + r) >> 1)
#define lc (p << 1)
#define rc ((p << 1) | 1)
using namespace std;
struct qq{
    int l, r, t;
};
bool cmp(qq a, qq b){
    return a.l > b.l;
}
array<int, 200004> x, ans;
array<int, 800004> X, S, M, tag;
vector<qq> Q;
void build(int p, int l, int r){
    if(l == r){
        X[p] = x[l];
        return;
    }
    build(lc, l, mid);
    build(rc, mid + 1, r);
    X[p] = X[lc] + X[rc];
}
void pull(int p){
    S[p] = S[lc] + S[rc];
    M[p] = max(M[lc], M[rc]);
}
void push(int p, int l, int r){
    if(!tag[p]) return;
    S[lc] = (mid - l + 1) * tag[p];
    S[rc] = (r - mid) * tag[p];
    M[lc] = M[rc] = tag[p];
    tag[lc] = tag[rc] = tag[p];
    tag[p] = 0;
}
int find(int p, int v, int l, int r){
    if(l == r) return l;
    push(p, l, r);
    if(M[lc] >= v) return find(lc, v, l, mid);
    else if(M[rc] >= v) return find(rc, v, mid + 1, r);
    else return r +1;
}
void update(int p, int ql, int qr, int v, int l, int r){
    if(ql > r || qr < l) return;
    if(l != r) push(p, l, r);
    if(ql <= l && qr >= r){
        S[p] = (r - l + 1) * v;
        M[p] = v;
        tag[p] = v;
        return;
    }
    update(lc, ql, qr, v, l, mid);
    update(rc, ql, qr, v, mid + 1, r);
    pull(p);
}
int query(int p, int ql, int qr, int l, int r){
    if(ql > r || qr < l) return 0;
    if(l != r) push(p, l, r);
    if(ql <= l && qr >= r) return S[p] - X[p];
    return query(lc, ql, qr, l, mid) + query(rc, ql, qr, mid + 1, r);
}
signed main(){
    int n, q, l, r, p = 0;
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> x[i];
    }
    build(1, 1, n);
    for(int i = 0; i < q; i++){
        cin >> l >> r;
        Q.pb({l, r, i});
    }
    sort(Q.begin(), Q.end(), cmp);
    for(int i = n; i > 0; i--){
        update(1, i, find(1, x[i], 1, n) - 1, x[i], 1, n);
        while(Q[p].l == i){
            ans[Q[p].t] = query(1, Q[p].l, Q[p].r, 1, n);
            p++;
        }
    }
    for(int i = 0; i < q; i++){
        cout << ans[i] << "\n";
    }
    return 0;
}