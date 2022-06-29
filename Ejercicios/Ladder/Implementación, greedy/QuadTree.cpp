#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second

struct Node {
    ll x, y, v;
    Node(ll x, ll y, ll v): x(x), y(y), v(v) {}
    Node() { x = y = v = -1; }
    Node(Node a, Node b, Node c, Node d) {
        if(a.v >= b.v and a.v >= c.v and a.v >= d.v) x = a.x, y = a.y, v = a.v;
        else if(b.v >= a.v and b.v >= c.v and b.v >= d.v) x = b.x, y = b.y, v = b.v;
        else if(c.v >= b.v and c.v >= a.v and c.v >= d.v) x = c.x, y = c.y, v = c.v;
        else if(d.v >= b.v and d.v >= c.v and d.v >= a.v) x = d.x, y = d.y, v = d.v;
    }
};

vector<Node> TT;

void upd(int n, int i1, int j1, int i2, int j2, int r1, int c1, int r2, int c2, int v){

	if (i1 > r2 || j1 > c2 || i2 < r1 || j2 < c1 || i1 > i2 || j1 > j2)
		return;

	if (i1 == i2 && j1 == j2) {
		TT[n] = Node(i1, j1, v);
        return;
    }

	Node mn(-1, -1, 0);

	int mi = i1 + (i2 - i1) / 2;
	int mj = j1 + (j2 - j1) / 2;

     
	upd(4 * n + 1, i1, j1, mi, mj, r1, c1, r2, c2, v);
	upd(4 * n + 2, mi + 1, j1, i2, mj, r1, c1, r2, c2, v);
	upd(4 * n + 3, i1, mj + 1, mi, j2, r1, c1, r2, c2, v);
	upd(4 * n + 4, mi + 1, mj + 1, i2, j2, r1, c1, r2, c2, v);

	TT[n] = Node(TT[4 * n + 1], TT[4 * n + 2], TT[4 * n + 3], TT[4 * n + 4]);
}

Node qry(int n, int i1, int j1, int i2, int j2, int r1, int c1, int r2, int c2){

	if (i1 > r2 || j1 > c2 || i2 < r1 || j2 < c1 || i1 > i2 || j1 > j2)
		return Node();

	if (i1 >= r1 && j1 >= c1 && i2 <= r2 && j2 <= c2)
		return TT[n];

	int mx = 0;

	int mi = i1 + (i2 - i1) / 2;
	int mj = j1 + (j2 - j1) / 2;

	Node A = qry(4 * n + 1, i1, j1, mi, mj, r1, c1, r2, c2);
	Node B = qry(4 * n + 2, mi + 1, j1, i2, mj, r1, c1, r2, c2);
	Node C = qry(4 * n + 3, i1, mj + 1, mi, j2, r1, c1, r2, c2);
	Node D = qry(4 * n + 4, mi + 1, mj + 1, i2, j2, r1, c1, r2, c2);

	return Node(A, B, C, D);
}


