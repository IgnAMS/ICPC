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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; 
    while(cin>>n>>m) {
        vi A(n); rep(i, n) cin>>A[i];
        vi Acc(n + 1, 0); rep(i, n) Acc[i + 1] = A[i] + Acc[i];
        
        vector<vector<vi>> C(n + 1, vector<vi>());
        rep(i, m) {
            int l, s, c; cin>>l>>s>>c; l--;
            ll reach = prev(upper_bound(Acc.begin(), Acc.end(), Acc[l] + s)) - Acc.begin();
            C[l].push_back({c, reach});
        }   
        rep(i, n) sort(C[i].begin(), C[i].end());

        vi D(n + 1, 1e10);
        D[0] = 0;
        priority_queue<vi, vector<vi>, greater<vi>> pq;
        pq.push({0, 0, 0}); // cost, node, last
        int x = 1;
        while(!pq.empty()) {
            ll u, d, last; 
            u = pq.top()[1], d = pq.top()[0], last = pq.top()[2]; pq.pop();
            if(D[u] < d) continue;
            for(auto& e: C[u]) {
                ll x = upper_bound(D.begin(), D.end(), d + e[0]) - D.begin();
                ll init = max(last + 1, x); 
                repx(i, init, e[1] + 1) if(D[i] > d + e[0]) {
                    D[i] = d + e[0];
                    pq.push({D[i], i, e[1]});
                }
                last = max(e[1], last);
            }
        } 
        cout<<(D[n] == 1e10? -1: D[n])<<'\n';
    }
    return 0;
}