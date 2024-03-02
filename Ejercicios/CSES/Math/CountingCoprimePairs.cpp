#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") // could make sigill runtime error
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(ll i=a; i<(int)b; i++)
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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    vector<vl> P(1e6+2, vl());
    ll lim = 1e6+1;
    for(int i = 2; i <= lim; i++) if(P[i].size() == 0) {
        for(int j = i; j <= lim; j += i) {
            P[j].pb(i);
        }
    }
    
    vl S(1e6+2, 0);
    ll n; cin>>n;
    vl A(n);
    rep(i, n) {
        cin>>A[i];
        repx(mask, 1, (1<<P[A[i]].size())) {
            ll num = 1, cont = 0;
            rep(j, P[A[i]].size()) {
                if(mask & (1<<j)) num *= P[A[i]][j], cont++;
            }
            S[num] += (cont&1? 1: -1); 
        }
    }

    ll ans = 0;
    rep(i, n) {
        if(A[i] == 1) {
            ans += n - 1;
            continue;
        }
        ll curr = 0;
        repx(mask, 1, (1<<P[A[i]].size())) {
            ll num = 1;
            rep(j, P[A[i]].size()) {
                if(mask & (1<<j)) num *= P[A[i]][j];
            }
            curr += S[num];
        }
        ans += (n - curr);
    }
    cout<<ans / 2<<'\n';

    return 0;
}