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
    int n; cin>>n;
    ll P[n]; rep(i, n) cin>>P[i];
    ll ans = 1e15;
    rep(mask, (1<<n)) {
        ll v1 = 0, v2 = 0;
        rep(i, n) {
            if(mask & (1<<i)) v1 += P[i];
            else v2 += P[i];
        }
        ans = min(ans, abs(v1 - v2));
    }
    cout<<ans<<'\n';


    return 0;
}