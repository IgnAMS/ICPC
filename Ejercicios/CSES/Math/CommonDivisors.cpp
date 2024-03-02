#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") // could make sigill runtime error
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
    vl A(n); rep(i, n) cin>>A[i];
    vl S(1e6+1, 0);
    rep(i, n) S[A[i]]++;
    
    ll ans = 1;
    vector<vl> P(1e6+1, vl());
    for(int i = 1; i <= 1e6; i++) {
        ll suma = 0;
        for(int j = i; j <= 1e6; j += i) {
            suma += S[j];
        }
        if(suma >= 2) ans = max(ans, (ll)i);
    }

    cout<<ans<<'\n';

    return 0;
}