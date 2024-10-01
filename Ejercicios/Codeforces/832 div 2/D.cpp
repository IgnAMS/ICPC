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

vi T(1000000);
void update(ll i, ll x, ll l, ll r, ll u = 0) {
    if(l == r) T[u] = x;
    else {
        ll m = (l + r) / 2;
        if(i <= m) update(i, x, l, m, 2 * u + 1);
        else update(i, x, m + 1, r, 2 * u + 2);
        T[u] = max(T[2 * u + 1], T[2 * u + 2]);
    }
}

ll query(ll i, ll j, ll l, ll r, ll u = 0) {
    if(i <= l and r <= j) return T[u];
    if(l > j or r < i) return 0;
    ll m = (l + r) / 2;
    return max(query(i, j, l, m, 2 * u + 1), query(i, j, m + 1, r, 2 * u + 2));
}





int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin>>n>>q;
    vi A(n); rep(i, n) cin>>A[i];
    rep(i, n) update(i, A[i], 0, n - 1);
    vi X(n + 1, 0); rep(i, n) X[i + 1] = X[i] ^ A[i];
    map<int, vi> Par, Imp;
    repx(i, 1, n + 1) {
        if(i % 2 == 0) {
            if(!Par.count(X[i])) Par[X[i]] = vi();
            Par[X[i]].push_back(i );
        }
        else {
            if(!Imp.count(X[i])) Imp[X[i]] = vi();
            Imp[X[i]].push_back(i);
        }
    }
    rep(i, q) {
        int l, r; cin>>l>>r;
        ll mx = query(l - 1, r - 1, 0, n - 1);
        if(mx == 0) cout<<0<<'\n';
        else if((r - l + 1) % 2 == 1 and X[r] == X[l - 1])  cout<<1<<'\n';
        else if((r - l + 1) % 2 == 1) cout<<"-1\n";
        else if(X[r] != X[l - 1]) cout<<"-1\n";
        else { // largo par, necesito descomponerlo en dos impares, debo ver si hay alguno impar no mas entre medio
            if(A[l - 1] == 0 or A[r - 1] == 0) cout<<1<<'\n';
            else if(l % 2 == 0) {
                auto it = lower_bound(Par[X[l - 1]].begin(), Par[X[l - 1]].end(), l);
                if(it == Par[X[l - 1]].end() or *it > r) cout<<"-1\n";
                else cout<<2<<'\n';
            }
            else {
                auto it = lower_bound(Imp[X[l - 1]].begin(), Imp[X[l - 1]].end(), l);
                if(it == Imp[X[l - 1]].end() or *it > r) cout<<"-1\n";
                else cout<<2<<'\n';
            }
        }
    }

    return 0;
}