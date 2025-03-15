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
    int t; cin>>t;
    while(t--) {
        ll n, k; cin>>n>>k;
        vector<pll> A(n); // [vida, dano]
        
        rep(i, n) cin>>A[i].ff; 
        rep(i, n) cin>>A[i].ss;

        sort(A.begin(), A.end());

        vl MinPow(n);
        MinPow[n - 1] = A[n - 1].ss;
        for(int i = n - 2; i >= 0; i--) MinPow[i] = min(MinPow[i + 1], A[i].ss);

        ll acc = 0;
        while(k > 0) {
            acc += k;
            ll ind = upper_bound(A.begin(), A.end(), pll(acc, 1e10)) - A.begin();
            if(ind == n) break;
            k -= MinPow[ind];
        }
        if(k > 0) cout<<"YES\n";
        else cout<<"NO\n";

    }


    return 0;
}