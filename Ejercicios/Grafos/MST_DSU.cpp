
vector<vector<ii>> T;

struct Edge{
    ll u, v, w;
    Edge(ll u, ll v, ll w): u(u), v(v), w(w) {}
    bool operator<(Edge& e) const { return w > e.w; }
};


struct MST{
    int n;
    vector<int> p;
    ll w = 0;
    MST(vector<Edge>& E, int a){
        n = a;
        p.assign(n, -1);
        sort(E.begin(), E.end());
        for(auto& e : E) join(e);
    }
    int find(int u){
        return p[u] < 0? p[u] = u: find(p[u]);
    }
    void join(Edge& e){
        int u = find(e.u), v = find(e.v);
        if(u == v) return;
        if(-p[v] > -p[u]) swap(u,v);
        w += e.w;
        T[e.u].emplace_back(e.v, e.w);
        T[e.v].emplace_back(e.u, e.w);
        p[u] += p[v], p[v] = u;
    }
};