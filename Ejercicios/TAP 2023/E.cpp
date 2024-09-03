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


ll check(ll i, ll x, ll A, ll R, ll S) {
    // i + m * x >= A, i + m * x <= R
    // m >= (A - i) / x, m <= (R - i) / x
    ll l = max((A - i) / x, 1LL), r = (R - i) / x;
    while(l < r) {
        ll m = (l + r) / 2;
        if(i + i * m + x * m * (m + 1) / 2 >= S) r = m;
        else l = m + 1;
    }
    if(l > r) return 0;
    return (i + i * l + x * l * (l + 1) / 2 == S);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll A, S, L, R; cin>>A>>S>>L>>R;
    ll ans = 0;
    // inicio que parte antes de A
    for(ll i = L; i <= A - 1; i++) {
        for(ll x = 1; x * x <= A - i; x++) if((A - i) % x == 0) {
            ans += check(i, x, A, R, S);
            if(x != (A - i) / x) ans += check(i, (A - i) / x, A, R, S);
        }
    }
    
    // inicio en A
    if(A == S) ans++;
    
    // A + m * A + x * m * (m + 1) / 2 >= S
    for(ll x = 1; x <= (R - A); x++) {
        ans += check(A, x, A, R, S);
    }
    cout<<ans<<'\n';



    return 0;
}