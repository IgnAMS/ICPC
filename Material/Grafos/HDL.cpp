#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;


#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt


const int N = 2e5+5;
const int S = (1<<19);

int n, q, V[N]; // V guarda el valor
vector<int> G[N];

int sz[N], P[N], D[N];
int st[S], id[N], tp[N];

ll op(ll x, ll y) { return min(x, y); }
ll neutro = 100001;

void update(int idx, int val) {
	st[idx += n] = val;
	for (idx /= 2; idx; idx /= 2)
		st[idx] = op(st[2 * idx], st[2 * idx + 1]);
}

int query(int lo, int hi) { // [lo, hi]
	int ra = neutro, rb = neutro;
	for (lo += n, hi += n + 1; lo < hi; lo /= 2, hi /= 2) {
		if (lo & 1)
			ra = op(ra, st[lo++]);
		if (hi & 1)
			rb = op(rb, st[--hi]);
	}
	return op(ra, rb);
}

ll path(int x, int y) {
	int ret = neutro;
	while(tp[x] != tp[y]) {
		if(D[tp[x]] < D[tp[y]]) swap(x, y);
        // cout<<"pregunto desde "<<tp[x]<<" hasta "<<x<<'\n';
        // cout<<query(id[tp[x]], id[x])<<'\n';
		ret = op(ret, query(id[tp[x]], id[x]));
		x = P[tp[x]];
	}
	if(D[x] > D[y]) swap(x, y);
    // cout<<"pregunto desde "<<x<<" hasta "<<y<<'\n';
    // cout<<query(id[x], id[y])<<'\n';
	ret = op(ret, query(id[x], id[y]));
	return ret;
}

int dfs_sz(int u, int p) {
	sz[u] = 1;
	P[u] = p;
	for(int v : G[u]) if(v != p) {
		D[v] = D[u] + 1;
		sz[u] += dfs_sz(v, u);
	}
	return sz[u];
}

int ct = 1;

void dfs_hld(int u, int p, int top) {
	id[u] = ct++;
	tp[u] = top;
	update(id[u], V[u]);
	int h = -1, h_sz = -1;
	for(int v : G[u]) if(v != p and sz[v] > h_sz) h_sz = sz[v], h = v;

	if(h == -1) return;
	dfs_hld(h, u, top); 
	for(int v : G[u]) if(v != p and v != h) dfs_hld(v, u, v);
}