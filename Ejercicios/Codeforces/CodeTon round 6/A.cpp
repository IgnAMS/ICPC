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
    int t; cin>>t;
    while(t--) {
        ll n, k, x; cin>>n>>k>>x;
        if(x + 1 < k or k > n) {
            cout<<"-1\n";
        }
        else {
            // cout<<k * (k - 1) / 2<<'\n';
            // cout<<(n - k) <<" "<<(k == x? k - 1: x)<<'\n';
            ll ans = k * (k - 1) / 2;
            if(k == x) ans += (n - k) * (k - 1);
            else ans += (n - k) * x;
            cout<<ans<<'\n';
        }

    }


    return 0;
}