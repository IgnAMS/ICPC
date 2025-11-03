#pragma GCC optimize("Ofast")
#include<iostream>
#include<vector>
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

const int mxN = 1e5+5;
const int INF = 1e9+1;
ll Cont[mxN];
pll Best[mxN], second[mxN];
vector<pll> Queries[mxN];
vector<pll> G[mxN];
ll Ans[mxN];

int n;

pll init(ll u, ll p) {
    pll best = {-1, 1e7};
    second[u] = best;
    if(G[u].size() == 1) best = {u, 0};
    
    for(auto [v, w]: G[u]) if(v != p) {
        pll op = init(v, u);
        op.ss += w;
        if(op.ss < best.ss or (op.ss == best.ss and op.ff < best.ff)) {
            second[u] = best;
            best = op;
        }
        else if(op.ss < second[u].ss or (second[u].ss == op.ss and op.ff < second[u].ss)) {
            second[u] = op;
        }
    }
    Best[u] = best;
    Cont[best.ff]++;
    return best;
}


void reroot(ll u, ll p, pll best) {
    for(auto [node, ind]: Queries[u]) {
        Ans[ind] = Cont[node];
    }
    // cout<<"la root es "<<u<<" con best "<<best.ff<<" y dist "<<best.ss<<"\n";
    // cout<<"Lista de valores: "; 
    // rep(i, n) cout<<Cont[i]<<", ";
    // cout<<"\n";

    for(auto [v, w]: G[u]) if(v != p) {
        pll new_best = {best.ff, best.ss + w};
        if(Best[v].ss < new_best.ss or (Best[v].ss == new_best.ss and Best[v].ff < new_best.ff)) {
            new_best = Best[v];
        }

        if(Best[v].ff != best.ff)  {
            Cont[Best[v].ff] -= 1;
            Cont[new_best.ff] += 1;
        }
        
        reroot(v, u, new_best);
        
        if(Best[v].ff != best.ff) {
            Cont[Best[v].ff] += 1;
            Cont[new_best.ff] -= 1;
        }
    }
}




int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    rep(i, n - 1) {
        int u, v, w; cin>>u>>v>>w; u--, v--;
        G[u].pb({v, w});        
        G[v].pb({u, w});        
    }
    init(0, -1);
    int Q; cin>>Q;
    rep(i, Q) {
        int s, t; cin>>s>>t; s--, t--;
        Queries[t].pb({s, i});
    }

    reroot(0, -1, Best[0]);
    rep(i, Q) cout<<Ans[i]<<"\n";


    return 0;
}