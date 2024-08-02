#include <bits/stdc++.h>
#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define ld long double
#define all(a) (a).begin(), (a).end()
#define vi vector<int>
#define vl vector<ll>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define mii map<int, int>
#define mll map<ll, ll>
#define REP(i, a, b) for(int i = (a); i < (b); i++)
#define printv(v) REP(i, 0, (v).size()) { cout << (v)[i] << (i != (v).size() - 1 ? " " : "\n"); }
#define pb push_back
using namespace std;

const ll MOD = 1e9 + 7;

vector<vector<int>> adj;

vi parent;
vi sz;

void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
}

int find_parent(int v) {
    if (parent[v] == v) return v;
    return parent[v] = find_parent(parent[v]);
}

void union_sets(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);

    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);

    parent[b] = a;
    sz[a] += sz[b];
}

void solve() {
    int n, m, D, a, b;
    cin >> n >> m >> D;

    adj.resize(n + 1);

    parent.resize(n + 1);
    sz.resize(n + 1);

    REP(i, 0, m) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    set<int> v1(adj[1].begin(), adj[1].end());

    REP(i, 1, n + 1) {
        make_set(i);
    }

    int dcnt = int(v1.size()) - D;
    vector<pi> ans;

    vector<bool> visited(n + 1, false);
    vi prev(n + 1, -1);
    queue<int> s;
    for (auto v : adj[1]) {
        s.push(v);
        prev[v] = -1;
    }

    int v;
    while (!s.empty()) {
        v = s.top();
        s.pop();

        if (visited[v]) continue;

        visited[v] = true;

        if(v1.count(v) && prev[v] != -1) {
            if(dcnt <= 0) continue;
            dcnt--;
        }
        
        if(prev[v] != -1) {
            ans.emplace_back(prev[v], v);
            union_sets(prev[v], v);
        }

        for(auto u : adj[v]) {
            if(u == 1 || visited[u]) continue;
            prev[u] = v;
            s.push(u);
        }
    }

    int cnt = 0;
    for (auto v : adj[1]) {
        if (find_parent(1) != find_parent(v)) {
            ans.emplace_back(1, v);
            union_sets(1, v);
            cnt++;
        }
    }


    for(auto [a, b]: ans) cout<<a<<' '<<b<<'\n';
    cout<<"cnt: "<<cnt<<", size: "<<sz[find_parent(1)]<<'\n';
    if (cnt != D || sz[find_parent(1)] != n) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    REP(i, 0, ans.size()) {
        cout << ans[i].first << " " << ans[i].second << "\n";
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }

    return 0;
}