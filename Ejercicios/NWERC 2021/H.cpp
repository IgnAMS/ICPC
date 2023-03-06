#include<bits/stdc++.h>
using namespace std;
#define repx(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) repx(i, 0, n)
typedef unsigned long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#define pb push_back
#define ff first
#define ss second

const int mxn = 5e5 + 10;
ll L[mxn], R[mxn], Acc[mxn], A[mxn], D[mxn];
int n;
ll cost(ll l, ll r) {
    if(l < r)  return Acc[r - 1] - Acc[l];
    return Acc[n] - Acc[l] + Acc[r - 1];
}


int main() {
    cin>>n;
    rep(i, n) cin>>A[i];
    // n = 5e5;
    // A[0] = 1e13;
    // repx(i, 1, n) A[i] = 1e13 - 1;
    vector<pll> S;
    rep(i, n) {
        while(!S.empty() and S.back().ff <= A[i]) S.pop_back();
        L[i + 1] = (S.empty()? 0: S.back().ss);
        S.pb({A[i], i + 1});
    }
    rep(i, n) {
        while(!S.empty() and S.back().ff <= A[i]) S.pop_back();
        L[i + 1] = (S.empty()? 0: S.back().ss);
        S.pb({A[i], i + 1});
    } 
    S.clear();
    for(int i = n - 1; i >= 0; i--) {
        while(!S.empty() and S.back().ff <= A[i]) S.pop_back();
        R[i + 1] = (S.empty()? n + 1: S.back().ss);
        S.pb({A[i], i + 1});
    } 
    for(int i = n - 1; i >= 0; i--) {
        while(!S.empty() and S.back().ff <= A[i]) S.pop_back();
        R[i + 1] = (S.empty()? n + 1: S.back().ss);
        S.pb({A[i], i + 1});
    }
    // rep(i, n) cout<<L[i + 1]<<' '; cout<<'\n';
    // rep(i, n) cout<<R[i + 1]<<' '; cout<<'\n';
    
    Acc[0] = 0;
    rep(i, n) Acc[i + 1] = Acc[i] + A[i];
    // cout<<cost(L[1], R[1])<<' '<<cost(L[7], R[7])<<endl;

    priority_queue<pll, vector<pll>, greater<pll>> pq; 
    rep(i, n) {
        D[i + 1] = A[i];
        pq.push({D[i + 1], i + 1});
    }
    while(!pq.empty()) {
        auto x = pq.top(); pq.pop();
        ll u = x.ss, d = x.ff;
        if(D[u] < d) continue;
        // cerr<<u<<' '<<d<<'\n';
        if(L[u] == 0 and R[u] == n + 1) continue; // maximo
        ll c = cost(L[u], R[u]);
        ll cr = 0;
        if(A[R[u] - 1] > d + c) cr = A[R[u] - 1] - d - c;
        ll cl = 0;
        if(A[L[u] - 1] > d + c) cl = A[L[u] - 1] - d - c;
        ll dr = d + cr;
        ll dl = d + cl;
        // cerr<<d<<' '<<c<<' '<<A[L[u] - 1]<<' '<<A[R[u]-1]<<'\n';
        if(D[R[u]] > dr) {
            // cerr<<"asigno1 "<<R[u]<<" con "<<d + max(0LL, A[R[u] - 1] - d - c)<<'\n';
            D[R[u]] = dr;
            pq.push({dr, R[u]});
        }
        if(D[L[u]] > dl) {
            // cerr<<"asigno2 "<<L[u]<<" con "<<d + max(0LL, A[L[u] - 1] - d - c)<<'\n';
            D[L[u]] = dl;
            pq.push({dl, L[u]});
        }
    }
    ll mx = 0;
    rep(i, n) {
        // cout<<D[i + 1]<<' '; 
        mx = max(D[i + 1], mx);    
    } 
    cout<<mx<<'\n';
    

}