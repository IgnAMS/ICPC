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
    int n, m; cin>>n>>m;
    vl S(n); 
    vector<db> X(n);
    rep(i, n) {
        cin>>S[i]>>X[i];
    }

    ll ans = 1;
    vl DP(n, 1);
    rep(i, n) {
        rep(j, i) if(S[i] >= S[j]) {
            DP[i] = max(DP[i], DP[j] + 1);
            ans = max(ans, DP[i]);
        }
    }
    cout<<n - ans<<'\n';



    return 0;
}