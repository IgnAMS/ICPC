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

const int mxN = 1e5+5;
ll cont[mxN], b[mxN], u[mxN];

vl D[mxN];


ll coprime(ll x) {
    ll ans = 0;
    for(auto d: D[x]) ans += cont[d] * u[d];
    return ans;
}

void update(ll a, ll x) {
    for(auto d: D[a]) cont[d] += x;
}



int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i = 1; i < mxN; i++) {
        for(int j = i; j < mxN; j += i) D[j].pb(i);
        if(i == 1) u[i] = 1;
        else if((i / D[i][1]) % D[i][1] == 0) u[i] = 0;
        else u[i] = -u[i / D[i][1]];
    }

    ll n; cin>>n;
    ll ans = 0;
    ll A[n]; 
    rep(i, n) {
        cin>>A[i];
        ans = max(ans, A[i]);
        b[A[i]] = 1;
    }

    for(int i = 1; i < mxN; i++) {
        for(int j = i; j < mxN; j += i) b[i] |= b[j];
    }

    vl s;
    for(ll i = mxN - 1; i > 0; i--) {
        if(!b[i]) continue;
        while(coprime(i)) {
            ans = max(ans, i * s.back());
            update(s.back(), -1);
            s.pop_back();
        }
        update(i, 1);
        s.pb(i);
    }

    cout<<ans<<'\n';

    return 0;
}