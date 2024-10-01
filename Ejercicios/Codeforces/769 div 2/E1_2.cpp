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
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt

vector<vector<ii>> T;
vi D1;
void dfs(int u, int p, int d) {
    D1[u] = d;
    for(auto v: T[u]) if(v.ff != p) dfs(v.ff, u, d + 1);
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        T.assign(n, vector<ii>()); D1.assign(n, 0);
        rep(i, n - 1) {
            int u, v; cin>>u>>v; u--, v--;
            T[u].push_back({v, 1}); T[v].push_back({u, 1});
        }
        dfs(0, -1, 0);

        int maxi = 0, ind = -1;
        rep(i, n) if(D1[i] > maxi) maxi = D1[i], ind = i;
        repx(i, 1, n + 1) {
            vi D2(n, 10000);
            vector<vector<ii>> T2 = T;
            T2[0].push_back({ind, i}); T2[ind].push_back({0, i});
            
            priority_queue<ii, vector<ii>, greater<ii>> pq;
            pq.push({0, 0}); D2[0] = 0;
            while(!pq.empty()) {
                ll d, u; tie(d, u) = pq.top(); pq.pop();
                if(D2[u] < d) continue;
                for(auto v: T2[u]) if(D2[v.ff] > d + v.ss) {
                    D2[v.ff] = d + v.ss; pq.push({D2[v.ff], v.ff});
                }
            }
            ll ans = 0;
            rep(i, n) ans = max(ans, D2[i]);
            cout<<ans<<'\n';
        }

    }





    return 0;
}