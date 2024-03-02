#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef vector<int> vi;
#define ff first
#define ss second
#define rep(i, n) for(int i = 0; i < n; i++)
#define repx(i, a, b) for(int i = (int)a; i < (int)b; i++)
ll M = 1e9 + 7;
vector<int> UpF, DownF;
vector<vi> segs;

class HLD
{

public:
    // ancestor, heavy, depht, component parent, index in ST
    vi A, H, D, R, P;

    int dfs(vector<vi> &G, int u)
    {
        int ans = 1, M = 0, s;
        for(int v : G[u]) if (v != A[u])
        {
            A[v] = u, D[v] = D[u] + 1;
            s = dfs(G, v), ans += s;
            if(s > M ) H[u] = v, M = s;
        }

        return ans;
    }

    void path(int u, int v)
    {
        bool d = 0; // d=0 Down, d=1 Up
        for(; R[u] != R[v]; v = A[R[v]])
        {
            if (D[R[u]] > D[R[v]]) swap(u, v), d = !d;
            // P[R[v]] esta mas arriba
            //cout << P[R[v]]+1 << " " << P[v] + 1<<" "<<d << endl;
            if(d) // up y reviso las que bajan
            {
                DownF[P[v]]++;
                //DownF[P[R[v]]]--;
            }
            else{
                UpF[P[v]]++;
                //UpF[P[R[v]]]--;
            }
            //if (d) //query P[R[v]], P[v]+1
            //else  //query P[R[v]], P[v]+1
        }
        if(D[u] > D[v]) swap(u, v), d = !d;
        // P[u] esta mas arriba
        if(d) // up y reviso las que bajan
        {
            DownF[P[v]]++;
            DownF[P[u]]--;
        }
        else{
            UpF[P[v]]++;
            UpF[P[u]]--;
        }
        //if(d) // P[u], P[v]
        //else // P[u], P[v]
        //cout << P[u]+1 << " " << P[v] + 1 << " "<<d << endl;

    }

    HLD(vector<vi> &G, int n) : A(n), D(n), R(n), P(n)
    {
        // st
        H.assign(n, -1); A[0] = -1, D[0] = 0; dfs(G, 0); int p = 0;
        rep(i, n) if(A[i] == -1 || H[A[i]] != i){
            
            vi nodes;
            for(int j = i; j != -1; j = H[j]) 
            {
                nodes.push_back(j);
                R[j] = i, P[j] = p++;
            }
            reverse(nodes.begin(), nodes.end());
            segs.push_back(nodes);
        }
    }
};


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vl p2(1000001, 0);
    ll mul = 1, ans = 0;
    
    rep(i, 1000001)
    {
        p2[i] = mul;
        mul = (mul * 2) % M;
    }

    int n, k;
    cin >> n;
    UpF.assign(n, 0);
    DownF.assign(n, 0);

    vector<vector<pair<int, int>>> g(n, vector<pair<int, int>>(0));
    vector<vi> g2(n, vi(0));
    rep(i, n-1)
    {
        int a, b, x;
        cin >> a >> b >> x;
        a--; b--;

        g[a].push_back({b, x});
        g[b].push_back({a, -x});
        g2[a].push_back(b);
        g2[b].push_back(a);
    }


    vi Up, Down;

    vector<int> vis(n, 0);
    Up.assign(n, 0); Down.assign(n, 0);

    queue<int>q;
    q.emplace(0);

    while(!q.empty())
    {
        ll k  = q.front(); q.pop();
        //cout << k+1 << " " << Up[k] << " " << Down[k] << endl;
        if(!vis[k])
        {
            vis[k] = 1;
            for(auto it : g[k])
            {
                int v = it.ff, x = it.ss;
                if(!vis[v])
                {
                    q.push(v); // Le doy al hijo la info de la arista
                    if(x == 1)
                        Down[v] = 1;
                        //cout << v+1 << "*\n";
                    else if(x == -1) Up[v] = 1;
                }
            }
        }
    }



    HLD hlf(g2, n);

    /*rep(i, n)
    {
        cout << hlf.R[i]<<endl;
    }
    cout << "hola"<<endl;*/

    cin >> k;
    int a_l = 0;
    rep(i, k)
    {
        int a_r;
        cin >> a_r;
        a_r--;
        //cout << a_l+1 << " " << a_r+1 << endl;
        hlf.path(a_l, a_r);
        a_l = a_r;
    }

    for (auto it : segs)
    {
        int acU = 0, acD = 0;

        for(auto node : it)
        {
            
            acU += UpF[hlf.P[node]];
            acD += DownF[hlf.P[node]];
            //cout << node << " " <<DownF[hlf.P[node]] << " "<<Down[node] << " "<<acD<<endl ;

            if(Up[node])
            {
                ans += (p2[acU] + M - 1) % M;
                ans %= M; 
            }
            if(Down[node])
            {
                ans += (p2[acD] + M - 1) % M;
                ans %= M; 
            }
        }
        //cout << endl;
        
    }

    cout << ans << "\n";    




    return 0;
}