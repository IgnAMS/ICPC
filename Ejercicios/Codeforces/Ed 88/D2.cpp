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


ll QR[400005], QL[400005];

void update(ll l, ll r, ll x, ll y, ll pos, ll u) {
    if(l == r) QR[u] = x, QL[u] = y;
    else {
        if(pos <= (l + r) / 2) update(l, (l + r) / 2, x, y, pos, 2 * u);
        else update((l + r) / 2 + 1, r, x, y, pos, 2 * u + 1);
        QL[u] = max(QL[2 * u], QL[2 * u + 1]);
        QR[u] = max(QR[2 * u], QR[2 * u + 1]);
    }
}

// i, j son query
ii query(ll i, ll j, ll l, ll r, ll u) {
    // cerr<<"query: "<<i<<' '<<j<<". Rango actual: "<<l<<' '<<r<<'\n';
    if(r < i or j < l) return { -10000000, -10000000 };
    if(i <= l and r <= j) return { QL[u], QR[u] };
    ii L = query(i, j, l, (l + r) / 2, 2 * u);
    ii R = query(i, j, (l + r) / 2 + 1, r, 2 * u + 1);
    return { max(L.ff, R.ff), max(L.ss, R.ss) };
}




int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    vector<vi> G(65), IG;
    int n; cin>>n;
    vi A(n); rep(i, n) cin>>A[i];
    vi Acc(n + 1, 0), Rev(n + 1, 0);
    rep(i, n) if(A[i] >= 0) {
        G[A[i]].push_back(i);
    }

    rep(i, n) Acc[i + 1] = Acc[i] + A[i];
    for(int i = n - 1; i >= 0; i--) Rev[i] = Rev[i + 1] + A[i];
    rep(i, n + 1) update(0, n, Acc[i], Rev[i], i, 1);
    
    ll ans = 0;
    rep(i, n) if(A[i] > 0) { // asumo que soy el maximo
        ll l = 0, r = n - 1;
        repx(j, A[i] + 1, 31) {
            auto itR = lower_bound(G[j].begin(), G[j].end(), i);
            if(itR != G[j].end()) 
                r = min(r, *itR - 1);

            auto itL = lower_bound(G[j].begin(), G[j].end(), i);
            if(G[j].end() != G[j].begin() and itL != G[j].begin()) 
                l = max(*prev(itL) + 1, l);
        }
        // pregunto por el maximo acc a la derecha
        ll L = query(l, i, 0, n, 1).ff;
        ll R = query(i + 1, r + 1, 0, n, 1).ss;
        ans = max(ans, (L == -10000000? 0: L) + (R == -10000000? 0: R) - Rev[i] - Acc[i + 1]);
    }
    cout<<ans<<'\n';




    return 0;
}