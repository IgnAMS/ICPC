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
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vi U(n); rep(i, n) cin>>U[i];
        vi S(n); rep(i, n) cin>>S[i];
        vector<vi> G(n, vi());
        rep(i, n) {
            U[i]--;
            G[U[i]].push_back(S[i]);
        } 
        for(auto& u: G) sort(u.begin(), u.end());
        set<ii> S2;
        rep(i, n) if(G[i].size() != 0) S2.insert({G[i].size(), i});
        vector<vi> A(n, vi());
        rep(i, n) {
            A[i] = vi(G[i].size() + 1, 0);
            rep(j, G[i].size()) A[i][j + 1] = G[i][j] + A[i][j];
        }

        repx(i, 1, n + 1) {
            ll ans = 0;
            for(auto it = S2.lower_bound(ii(i, 0)); it != S2.end(); it++) {
                ll u = (*it).ss, s = (*it).ff;
                ans += A[u][s] - A[u][s % i];
                // cout<<"de la universidad "<<u<<" consigo "<<A[u][s] - A[u][s % i]<<'\n';
            }
            cout<<ans<<' ';
        }
        cout<<'\n';
    }





    return 0;
}