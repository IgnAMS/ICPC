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
    int k; cin>>k;
    ll ans = 100000000;
    rep(i, k) {
        ll a, b, c; cin>>a>>b>>c;
        ll xd = b * c / __gcd(b, c);
        // a + xd * t >= 2022 -> t >= (2022 - a) / xd
        ll aux = (2022 - a + (xd - 1)) / xd;
        ans = min(ans, aux * xd + a); 
    }
    cout<<ans<<'\n';

    return 0;
}