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

vl A[] = {
    {0, 1, 0, 0, 1}, // a lo mas n/2
    {0, 0, 1, 1, 0}, // a lo mas n/2
    {0, 1, 2, 0, 0}, // a lo mas n/3
    {0, 2, 0, 1, 0}, // a lo mas n/3
    {0, 3, 1, 0, 0}, // a lo mas n/4
    {0, 5, 0, 0, 0}  // a lo mas n/5
};

// [0 1 2 1 0]
// (n / 2) * (n / 2) * (n / 3) * (n / 3) * (n / 4) * (n / 5)    


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vl C(5, 0);
    rep(i, n) {
        ll x; cin>>x;
        C[x % 5]++;
    }

    vector<vl> X;
    rep(a, 5) {
        if(a % 5 == 0) X.pb({a});
        rep(b, 5) {
            if((a + b) % 5 == 0) X.pb({a, b});
            rep(c, 5) {
                if((a + b + c) % 5 == 0) X.pb({a, b, c});
                rep(d, 5) {
                    if((a + b + c + d) % 5 == 0) X.pb({a, b, c, d});
                    rep(e, 5) {
                        if((a + b + c + d + e) % 5 == 0) X.pb({a, b, c, d, e});
                    }
                }
            }
        }    
    } 
    sort(X.begin(), X.end(), [](const vl& a, const vl& b){
        return a.size() < b.size();
    });
    
    ll ans = 0;
    for(auto& vec: X) {
        ll mn = 1e6;
        vl F(5, 0);
        for(auto u: vec) F[u]++;
        rep(i, 5) if(F[i] != 0) mn = min(mn, C[i] / F[i]);
        ans += mn;
        rep(i, 5) C[i] -= mn * F[i]; 
    }
    cout<<ans<<'\n';


    return 0;
}