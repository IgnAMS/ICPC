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
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

struct Node {
    ll x, y, v;
    Node(ll x, ll y, ll v): x(x), y(y), v(v) {}
    Node() { x = y = v = -1; }
    Node(Node a, Node b, Node c, Node d) {
        if(a.v >= max({b.v, c.v, d.v})) x = a.x, y = a.y, v = a.v;
        else if(b.v >= max({a.v, c.v, d.v})) x = b.x, y = b.y, v = b.v;
        else if(c.v >= max({a.v, b.v, d.v})) x = c.x, y = c.y, v = c.v;
        else if(d.v >= max({a.v, b.v, c.v})) x = d.x, y = d.y, v = d.v;
    }
};


ll r, c, INF = 1e12;
vector<vi> V, R, C;
vector<Node> TT(1000000);

void upd(ll r1, ll c1, ll v, int n = 0, int i1 = 0, int j1 = 0, int i2 = r - 1, int j2 = c - 1){
    // 1. i1 <= r1 and r1 <= i2 -> i1 > r1 or r1 > i2
    // 2. j1 <= c1 and c1 <= j2 -> j1 > c1 or c1 > j2
	if(i1 > r1 or j1 > c1 or i2 < r1 or j2 < c1 or i1 > i2 or j1 > j2)
		return;

	if(i1 == i2 and j1 == j2) {
        // cout<<"toy en el punto "<<i1<<' '<<j1<<" y actualizo a "<<v<<'\n';
		TT[n] = Node(i1, j1, v);
        return;
    }

	int mi = i1 + (i2 - i1) / 2;
	int mj = j1 + (j2 - j1) / 2;

     
	upd(r1, c1, v, 4 * n + 1, i1, j1, mi, mj);
	upd(r1, c1, v, 4 * n + 2, mi + 1, j1, i2, mj);
	upd(r1, c1, v, 4 * n + 3, i1, mj + 1, mi, j2);
	upd(r1, c1, v, 4 * n + 4, mi + 1, mj + 1, i2, j2);

	TT[n] = Node(TT[4 * n + 1], TT[4 * n + 2], TT[4 * n + 3], TT[4 * n + 4]);
}

Node qry(ll r1, ll c1, ll r2, ll c2, int n = 0, int i1 = 0, int j1 = 0, int i2 = r - 1, int j2 = c - 1){

	if (i1 > r2 || j1 > c2 || i2 < r1 || j2 < c1 || i1 > i2 || j1 > j2)
		return Node();

	if(r1 <= i1 and i2 <= r2 and c1 <= j1 and j2 <= c2)
		return TT[n];


	int mi = i1 + (i2 - i1) / 2;
	int mj = j1 + (j2 - j1) / 2;

	Node A = qry(r1, c1, r2, c2, 4 * n + 1, i1, j1, mi, mj);
	Node B = qry(r1, c1, r2, c2, 4 * n + 2, mi + 1, j1, i2, mj);
	Node C = qry(r1, c1, r2, c2, 4 * n + 3, i1, mj + 1, mi, j2);
	Node D = qry(r1, c1, r2, c2, 4 * n + 4, mi + 1, mj + 1, i2, j2);

	return Node(A, B, C, D);
}


ll dijkstra(ii s, ii t) {
    // Setear el ST
    rep(i, r) rep(j, c) upd(i, j, INF);
    
    vector<vi> D(r, vi(c, 1e12));
    D[s.ff][s.ss] = 0;
    upd(s.ff, s.ss, 0);

    
    priority_queue<vi, vector<vi>, greater<vi>> pq;
    pq.push({0, 0, s.ff, s.ss}); 
    while(!pq.empty()) {
        ll x, y, d; 
        x = pq.top()[2], y = pq.top()[3], d = pq.top()[0]; pq.pop();
        if(D[x][y] < d) continue;
        ii x0 = {x - R[x][y], y - C[x][y]}, x1 = {x + R[x][y], y + C[x][y]};
        Node xQ = qry(x0.ff, x0.ss, x1.ff, x1.ss);
        while(xQ.v > d + V[x][y]) {
            ii aux = { xQ.x, xQ.y };
            D[aux.ff][aux.ss] = d + V[x][y];
            upd(aux.ff, aux.ss, d + V[x][y]);
            pq.push({d + V[x][y], V[aux.ff][aux.ss], aux.ff, aux.ss});
            xQ = qry(x0.ff, x0.ss, x1.ff, x1.ss);
        }
    }
    return D[t.ff][t.ss];
}




int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>r>>c>>n;
    V.assign(r, vi(c, 0)); rep(i, r) rep(j, c) cin>>V[i][j];
    R.assign(r, vi(c, 0)); rep(i, r) rep(j, c) cin>>R[i][j];
    C.assign(r, vi(c, 0)); rep(i, r) rep(j, c) cin>>C[i][j];
    vector<ii> P(n);
    rep(i, n) cin>>P[i].ff>>P[i].ss;
    rep(i, n) P[i].ff--, P[i].ss--;
    rep(i, n - 1) {
        // cerr<<"empiezo el dijkstra\n";
        ll x = dijkstra(P[i], P[i + 1]);
        cout<<(x == 1e12? -1: x)<<" \n"[i == n - 2];
    }

    return 0;
}