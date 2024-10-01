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


// DP[i][x] = max(DP[i + 1][x], DP[i + 1][x] )

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        ll n, l, r; cin>>n>>l>>r;
        vl A(n); rep(i, n) cin>>A[i];
        
        multiset<ll> S;
        ll ans = 0;
        ll curr = 0;
        rep(i, n) {
            curr += A[i];
            S.insert(A[i]);
            while(curr > r) {
                curr -= *S.begin();
                S.erase(S.find(*S.begin()));
            }
            if(l <= curr and curr <= r) ans++, curr = 0, S.clear();
        }
        cout<<ans<<'\n';
    }





    return 0;
}