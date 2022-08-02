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

vi TX(400005, 1e7), TY(400005, 1e7);

void update(ll x, int pos, vi &T, int l = 0, int r = 100000, int u = 0) {
    if(l == r) T[u] = min(x, T[u]);
    else {
        ll m = (l + r) / 2;
        if(pos <= m) update(x, pos, T, l, m, 2 * u + 1);
        else update(x, pos, T, m + 1, r, 2 * u + 2);
        T[u] = min(T[2 * u + 1], T[2 * u + 2]);
    }
}

ll query(int i, int j, vi &T, int l = 0, int r = 100000, int u = 0) {
    if(i <= l and r <= j) return T[u];
    if(r < i or j < l) return 1e7;
    int m = (l + r) / 2;
    return min(query(i, j, T, l, m, 2 * u + 1), query(i, j, T, m + 1, r, 2 * u + 2));
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vi X(n); rep(i, n - 1) cin>>X[i];
    vi Y(n); rep(i, n - 1) cin>>Y[i];

    vi LX(n + 1, 100000000); vi RX(n + 1, 100000000), DY(n + 1, 100000000), UY(n + 1, 100000000); 
    ll l = 100000000, d = 100000000;
    rep(i, n - 1) {
        if(X[i] == 1) l = 0;
        if(Y[i] == 1) d = 0;
        LX[i + 1] = l++, DY[i + 1] = d++;
    }
    ll r = 100000000, u = 100000000;
    for(int i = n - 2; i >= 0; i--) {
        if(X[i] == 1) r = 0; 
        if(Y[i] == 1) u = 0;
        RX[i] = r++, UY[i] = u++;
    }

    rep(i, n) update(RX[i], i, TX), update(LX[i], i, TX);
    rep(i, n) update(DY[i], i, TY), update(UY[i], i, TY);
    


    vi AX(n, 0), AY(n, 0);
    rep(i, n - 1) AX[i + 1] = AX[i] + X[i];
    rep(i, n - 1) AY[i + 1] = AY[i] + Y[i];

    int q; cin>>q;
    rep(i, q) {
        ll x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2; x1--, y1--, x2--, y2--;
        ll dx = abs(x1 - x2), dy = abs(y1 - y2);
        ll k = abs(dx - dy) / 2;
        ll aux;
        if(dy > dx) aux = query(min(x1, x2), max(x1, x2), TX);
        else aux = query(min(y1, y2), max(y1, y2), TY);
        ll ans = aux >= k? 10 * k: aux * 10 + (k - aux) * 2;
        cout<<AX[max(x1, x2)] - AX[min(x1, x2)] + AY[max(y1, y2)] - AY[min(y1, y2)] + ans<<'\n';
    }



    return 0;
}