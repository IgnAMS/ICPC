#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(ll i=a; i<b; i++)
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

ll n, m;


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    
    vl suma(21, 0);
    vl X(21 * m, 0);
    ll curr = 0;
    repx(i, 1, 21) {
        repx(j, 1, m + 1) if(!X[i * j]) {
            X[i * j] = 1;
            curr++;
        }
        suma[i] = curr;
    }
    
    vl S(n + 1, 0);
    ll ans = 1;
    repx(i, 2, n + 1) {
        if(S[i]) continue;
        ll x = 1;
        ll k = 0;
        while(x <= n / i) {
            k++;
            x *= i; 
            S[x] = 1;
        }
        ans += suma[k];
    }
    cout<<ans<<'\n';

    return 0;
}