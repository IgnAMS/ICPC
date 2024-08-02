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

ll sol2(vl& A, ll k) {
    ll ans = 0;
    ll n = A.size();
    rep(i, (n + k - 1) / k) {
        ans += 2 * A[n - i * k - 1];
    }
    return ans;
}

ll sol1(vl& A, ll k) {
    ll ans = 0;
    ll n = A.size();
    rep(i, (n + k - 1) / k) {
        if(i == 0) ans += A[n - 1 - i * k];
        else ans += 2 * A[n - 1 - i * k];
    }
    return ans;
}



int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n, k; cin>>n>>k;
        vl Pos, Neg; 
        rep(i, n) {
            ll x; cin>>x;
            if(x < 0) Neg.pb(-x);
            else Pos.pb(x);
        }
        sort(Pos.begin(), Pos.end());
        sort(Neg.begin(), Neg.end());
        

        // cout<<sol1(Pos, k) + sol2(Neg, k)<<", "<<sol1(Neg, k) + sol2(Pos, k)<<'\n';
        // cout<<sol1(Pos, k)<<' '<<sol2(Neg, k)<<", "<<sol1(Neg, k)<<' '<<sol2(Pos, k)<<'\n';
        cout<<min(sol1(Pos, k) + sol2(Neg, k), sol1(Neg, k) + sol2(Pos, k))<<'\n';
    }

    return 0;
}