#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef double db;
typedef vector<ll> vi;
typedef pair<db, ll> dbll;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

int n;
vector<vector<vi>> G;
double f(double t) { 
    vector<db> D(n, 1e17);
    D[0] = 0;
    priority_queue<dbll, vector<dbll>, greater<dbll>> pq;
    pq.push({0, 0});
    while(!pq.empty()) {
        ll u; db d; u = pq.top().ss, d = pq.top().ff; pq.pop();
        if(D[u] < d) continue;
        // for(auto& e: G[u]) cerr<<e[0]<<' '<<e[1]<<' '<<e[2]<<'\n';
        for(auto& e: G[u]) if(D[e[0]] > D[u] + e[1] * t + e[2]) {
            D[e[0]] = D[u] + e[1] * t + e[2];
            pq.push({D[e[0]], e[0]});
        }
    }
    return D[n - 1];
}


double max_ternary_search(double l, double r, int times) {
    while (times--) {
        double d = (r - l) / 3.0;
        double m1 = l + d, m2 = r - d;
        double f1 = f(m1), f2 = f(m2);
        if (f1 >= f2) r = m2;
        if (f1 <= f2) l = m1;
    }
    return f((l+r)*.5);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int m;
    while(cin>>n>>m) {
        G.assign(n, vector<vi>());
        rep(i, m) {
            int u, v, a, b; cin>>u>>v>>a>>b; u--, v--;
            G[u].push_back({v, a, b}); G[v].push_back({u, a, b});
        }
        // max min{sum A_i * t + B_i}, maximizar una funcion concava, TS
        cout<<setprecision(5)<<fixed<<max_ternary_search(0, 1440, 100)<<'\n';
    }

    return 0;
}