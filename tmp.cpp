#include <bits/stdc++.h>
using namespace std;

#define lc (p << 1)
#define rc ((p << 1) | 1)
const int maxn = 2e5 + 1;

struct node {
    int val, tag;
    int l, r;
} t[maxn << 2];

vector<int> num(maxn);
vector<int> a(maxn);

void pull (int p) {
    t[p].val = t[lc].val + t[rc].val;
}

void push (int p) {
    if (t[p].tag != -1) {
        t[lc].tag = t[p].tag;
        t[rc].tag = t[p].tag;
        t[lc].val = t[p].tag * (t[lc].r - t[lc].l + 1);
        t[rc].val = t[p].tag * (t[rc].r - t[rc].l + 1);
        t[p].tag = -1;
    }
}

void build (int p, int l, int r) {
    t[p].l = l, t[p].r = r;
    t[p].tag = -1;
    if (l == r) {
        t[p].val = num[l];
        return;
    }

    int mid = (l + r) / 2;
    build(lc, l, mid);
    build(rc, mid + 1, r);
    pull(p);
}

void update (int p, int ql, int qr, int c) {
    if (t[p].l >= ql && t[p].r <= qr) {
        if (c == 1) {
            t[p].val = (t[p].r - t[p].l + 1) * c;
        } else {
            t[p].val = 0;
        }
        t[p].tag = c;
        return;
    }

    push(p);
    int mid = t[p].l + t[p].r >> 1;
    if (ql <= mid) {
        update(lc, ql, qr, c);
    } 
    if (qr > mid) {
        update(rc, ql, qr, c);
    }
    pull(p);
}

int query0 (int p, int ql, int qr) {
    if (t[p].l >= ql && t[p].r <= qr) {
        return t[p].r - t[p].l + 1 - t[p].val;
    }

    push(p);
    int mid = t[p].l + t[p].r >> 1;
    int ans = 0;
    if (ql <= mid) {
        ans += query0(lc, ql, qr);
    }
    if (qr > mid) {
        ans += query0(rc, ql, qr);
    }
    return ans;
}

int query1 (int p, int ql, int qr) {
    if (t[p].l >= ql && t[p].r <= qr) {
        return t[p].val;
    }
    push(p);
    int mid = t[p].l + t[p].r >> 1;
    int ans = 0;
    if (ql <= mid) {
        ans += query1(lc, ql, qr);
    }
    if (qr > mid) {
        ans += query1(rc, ql, qr);
    }
    return ans;
}

int query (int p) {
    if (t[p].l == t[p].r) {
        return t[p].l;
    }
    push(p);
    if (t[rc].val) {
        return query(rc);
    } else {
        return query(lc);
    }
}






signed main()
{
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		num[a[i]]++;
	}
	for(int i=1;i<=2e5+900;i++)
	{
		num[i+1]+=num[i]/2;
		num[i]%=2;
	}
	build(1,1,2e5+900);
	while(q--)
	{
		int k,L;
		scanf("%d %d",&k,&L);
		int res=a[k];
		if(query1(1,res,res)==1) update(1,res,res,0);
		else
		{
			int l=res,r=2e5+900;
			while(l<r)
			{
				int mid=l+r>>1;
				if(query1(1,res,mid)>=1) r=mid;
				else l=mid+1; 
			}
			
			update(1,res,l-1,1);
			update(1,l,l,0);
		}
		a[k]=L;
		if(query1(1,L,L)==0) update(1,L,L,1);
		else
		{
			int l=L,r=2e5+900;
			while(l<r)
			{
				int mid=l+r>>1;
				if(query0(1,L,mid)>=1) r=mid;
				else l=mid+1; 
			}
			update(1,L,l-1,0);
			update(1,l,l,1);
 
		}
		printf("%d\n",query(1));
	}
	
	
}