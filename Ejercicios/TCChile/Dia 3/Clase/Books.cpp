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
    int n, t; cin>>n>>t;
    vl A(n); rep(i, n) cin>>A[i];
    ll i = 0;
    ll curr = 0;
    ll ans = 0;
    rep(j, n) {
        curr += A[j];
        while(curr > t) curr -= A[i], i++;
        ans = max(ans, j - i + 1);
    }
    cout<<ans<<'\n';


    return 0;
}