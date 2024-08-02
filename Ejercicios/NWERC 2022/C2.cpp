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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll s; cin>>s;

    db l = 0, r = 2e5;
    rep(_, 80) {
        db m = (l + r) * 0.5;
        ll cnt = 0;
        for(ll x = 1; x <= m; x++) {
            cnt += ll(sqrt(m * m - x * x));
        }
        if(4 * cnt >= s + 1) r = m;
        else l = m;
    }
    cout<<setprecision(16)<<fixed<<(l + r) * 0.5<<'\n';

    return 0;
}