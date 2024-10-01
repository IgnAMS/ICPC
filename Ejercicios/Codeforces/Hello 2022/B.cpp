#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
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

const ll INF = 1e10;

void solve() {
    int n; cin>>n;
    set<array<ll, 3>> L, R; // [position, sum, index]

    ll best[] = {INF, -INF, INF};
    rep(i, n) {
        ll l, r, c; cin>>l>>r>>c;
        L.insert({l, c, -i});
        R.insert({-r, c, -i});
        auto [pl, c1, i1] = *L.begin();
        auto [pr, c2, i2] = *R.begin();
        pr = -1 * pr;
        ll cost = (c1 + c2 - (i1 == i2? c1: 0LL));

        // cout<<pl<<' '<<c1<<' '<<i1<<'\n';
        // cout<<pr<<' '<<c2<<' '<<i2<<'\n';
        // cout<<cost<<'\n';

        if((l < best[0] and best[1] <= r) or (l <= best[0] and best[1] < r)) {
            best[0] = l, best[1] = r, best[2] = c;
        }
        else if(l == best[0] and r == best[1] and best[2] > c) {
            best[2] = c;
        }

        if(pl < best[0] or pr > best[1] or (pl == best[0] and pr == best[1] and cost < best[2])) {
            best[0] = pl, best[1] = pr, best[2] = cost;
        }
        
        cout<<best[2]<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        solve();
    }


    return 0;
}