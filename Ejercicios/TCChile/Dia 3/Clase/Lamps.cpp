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
        int n; cin>>n;
        vector<pll> A(n);
        rep(i, n) cin>>A[i].ff>>A[i].ss;
        sort(A.begin(), A.end(), [&](const pll a, const pll b) {
            if(a.ff == b.ff) return a.ss > b.ss;
            return a.ff < b.ff;
        });
        
        // rep(i, n) cout<<A[i].ff<<' '<<A[i].ss<<'\n';
        
        ll ans = 0;
        multiset<ll> S;
        ll broken = 0;
        rep(j, n) {
            while(j < n and A[j].ff <= broken) j++;
            if(j == n) break;
            ans += A[j].ss;
            S.insert(A[j].ff);
            broken = max(broken, (ll)S.size());
            while(!S.empty() and *S.begin() <= broken) {
                S.erase(*S.begin());
            }
        }
        cout<<ans<<'\n';

    }

    return 0;
}