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
    ll n; cin>>n;
    vl A(n); rep(i, n) cin>>A[i];
    db ans = 0;
    ll curr = 0;
    rep(i, n) {
        curr += A[i];
        ans = max(ans, db(curr) / db(i + 1));
    }
    curr = 0;
    for(int i = n - 1; i >= 0; i--) {
        curr += A[i];
        ans = max(ans, db(curr) / db(n - i));
    }
    cout<<setprecision(10)<<fixed<<ans<<'\n';


    return 0;
}