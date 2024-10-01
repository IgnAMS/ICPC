#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> pll;
typedef double db;
typedef vector<ll> vl;
#define ff first
#define ss second
#define pb push_back
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

const int maxn = 200010;
int n;
vl G[maxn];
bool is_removed[maxn];
int subtree_size[maxn];

int get_subtree_size(int node, int parent = -1) {
	subtree_size[node] = 1;
	for (int child : G[node]) {
		if (child == parent || is_removed[child]) { continue; }
		subtree_size[node] += get_subtree_size(child, node);
	}
	return subtree_size[node];
}

int get_centroid(int node, int tree_size, int parent = -1) {
	for (int child : G[node]) {
		if (child == parent || is_removed[child]) { continue; }
		if (subtree_size[child] * 2 > tree_size) {
			return get_centroid(child, tree_size, node);
		}
	}
	return node;
}

ll Ans[maxn];
void build_centroid_decomp(int node = 0, ll val = 0) {
	int centroid = get_centroid(node, get_subtree_size(node));
	// for (int child : G[centroid]) {
	// 	if (is_removed[child]) { continue; }
	// 	get_dists(child, centroid, centroid);
	// }
    Ans[centroid] = val;

    // cout<<centroid<<'\n';


	is_removed[centroid] = true;
	for (int child : G[centroid]) {
		if (is_removed[child]) { continue; }
		build_centroid_decomp(child, val + 1);
	}
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    rep(i, n - 1) {
        int u, v; cin>>u>>v; u--, v--;
        G[u].pb(v); G[v].pb(u);
    }

    build_centroid_decomp(0);
    bool imp = 0;
    // cout<<char('A' + 25)<<'\n';
    rep(i, n) if(Ans[i] >= 26) imp = 1;
    if(imp) cout<<"Impossible\n";
    else {
        rep(i, n) cout<<char('A' + Ans[i])<<' '; cout<<'\n';
    }
    return 0;
}