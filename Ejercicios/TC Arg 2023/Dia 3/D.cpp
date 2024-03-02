#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i<(int)n; ++i)
#define repx(i, a, b) for(int i = a; i<(int)b; ++i)
#define ll long long
#define vl vector<ll>
#define ff first
#define ss second
#define pb push_back

const int mxN = 3e5+5;

struct Dinic{
    struct edge{
        int to, rev;
        ll f, cap;
    };
    vector<vector<edge>> g;
    vector<ll> dist;
    vector<int> q, work;
    int n, sink;

    bool bfs(int start, int finish){
        dist.assign(n, -1); 
        dist[start] = 0;
        int head = 0, tail = 0;
        q[tail++] = start;
        while(head < tail){
            int u = q[head++];
            for(const edge &e : g[u]){
                int v = e.to;
                if(dist[v] == -1 and e.f < e.cap){
                    dist[v] = dist[u] + 1;
                    q[tail++] = v;
                } 
            }
        }
        return dist[finish] != -1;
    }
    
    ll dfs(int u, ll f){
        if(u == sink){
            return f;
        }
        for(int &i = work[u]; i<(int)g[u].size(); ++i){
            edge &e = g[u][i];
            int v = e.to;
            if(e.cap <= e.f or dist[v] != dist[u]+1) continue;
            ll df = dfs(v, min(f, e.cap - e.f));
            if(df > 0){
                e.f += df;
                g[v][e.rev].f -= df;
                return df;
            }
        }
        return 0;
    }

    Dinic(int n){
        this -> n = n;
        g.resize(n);
        dist.resize(n);
        q.resize(n);
    }

    void add_edge(int u, int v, ll cap){
        edge a = {v, (int)g[v].size(), 0, cap};
        edge b = {u, (int)g[u].size(), 0, 0};
        g[u].push_back(a);
        g[v].push_back(b);
    }

    ll max_flow(int source, int dest){
        sink = dest;
        ll ans = 0;
        while(bfs(source, dest)){
            work.assign(n, 0);
            while(ll delta = dfs(source, LLONG_MAX)) ans += delta;
        }
        return ans;
    }
};

Dinic Din(100*500+2+100);
int Source = 50000+100, Target = 50001+100;
int a, b, n;
vector<vector<int>> S, E;


pair<int,int> decodificar(int entrada)
{
    int decode = (entrada/2) % (a * b);
    return {decode / b, decode % b};
}

int codificar(int i, int j, int t)
{
    int node = (i * b + j + (t*a*b)) * 2;
    return node;
}

void addNextLevelEdges(int t)
{
    int dx[5] = {-1, 1, 0, 0, 0};
    int dy[5] = {0, 0, 0, -1, 1};
    rep(i, a)
    {
        rep(j, b){

            rep(z, 5)
            {
                int ni = i + dx[z], nj = j + dy[z];
                if(ni < 0 || ni >= a || nj < 0 || nj >= b)
                    continue;
                
                int start = codificar(i, j, t);
                int end = codificar(ni, nj, t+1);

                Din.add_edge(start+1, end, 1);
            }

        }
    }
}


vector<pair<int,int>> path(int node)
{
    vector<pair<int,int>> p;
    int cont = 0;
    while(node < 50000)
    {
        cont++;
        //cout <<"("<<decodificar(node).first << ", "<<decodificar(node).second << "), ";
        if(cont % 2 == 0)
        {
            p.push_back({decodificar(node).first, decodificar(node).ss});
        }
        for(auto it : Din.g[node])
        {
            if(it.f == 1)
            {
                node = it.to;
                break;
            }
        }
    }
    return p; 
}

void initLevel(int t)
{
    rep(i, a)
    {
        rep(j, b)
        {
            // Nodo Virtual
            int start = codificar(i, j, t);
            Din.add_edge(start, start+1, 1);

            if(S[i][j] && t == 0)
                Din.add_edge(Source, start, 1);

            if(E[i][j] > 0)
                Din.add_edge(start+1, 50000+E[i][j]-1, 1); 
        }
    }
}



int main() {

    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> a >> b;

    S.assign(a, vector<int>(b, 0));
    E.assign(a, vector<int>(b, 0));

    rep(i, n)
    {
        int x, y;
        cin >> x >> y;
        S[x-1][y-1]=1;
    }

    rep(i, n)
    {
        int x, y;
        cin >> x >> y;
        E[x-1][y-1]=i+1;
        Din.add_edge(50000+i, Target, 1);
    }

    initLevel(0);
    
    int ac = 0, t =0;

    rep(i, 101)
    {
        initLevel(i+1);
        addNextLevelEdges(i);
        ac += Din.max_flow(Source, Target);
        //cout << ac << endl;
        t++;
        if(ac == n)break;  
    }
    cout << t<< "\n";
    int dx[5] = {-1, 1, 0, 0, 0};
    int dy[5] = {0, 0, 0, -1, 1};
    char name[5] = {'D','U','S','R','L'};
    for(auto it : Din.g[Source])
    {
        //cout << it.to <<" "<< it.f << endl;
        vector<pair<int, int>> p = path(it.to);

        cout<< p[0].first+1<<" "<<p[0].second+1 << " "<<p.back().first+1 << " " << p.back().ss+1 << " ";
        string s = "";
        rep(i, (int)p.size()-1)
        {
            rep(z, 5)
            {
                int x1, y1, x2, y2;
                tie(x1, y1) = p[i];
                tie(x2, y2) = p[i+1];
                x2 += dx[z];
                y2 += dy[z];
                if(x1 == x2 && y1 == y2)
                {
                    s += name[z];
                    break;
                }

            }

        }
        while(s.size() < t) s+='P';
        
        cout << s << "\n";
    }

}