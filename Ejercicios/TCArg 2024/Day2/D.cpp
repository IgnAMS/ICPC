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

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, d; cin>>n>>d;
    vl P;
    repx(i, 2, 1001) {
        bool primo = 1;
        for(int j = 2; j * j <= i; j++) if(i % j == 0) primo = 0;
        if(primo) P.pb(i); 
    }

    vl A(n);
    vector<db> Calc(n, 0);
    rep(i, n) {
        cin>>A[i];  
        ll x = A[i];
        for(auto p: P) {
            ll c = 0;
            while(x % p == 0) c++, x /= p;
            Calc[i] += log2(p) * c;
        }
    }
    db DP[n + 1][10];
    pll Pi[n + 1][10];
    rep(i, n + 1) rep(b, 10) DP[i][b] = -1e15;
    DP[0][1] = 0;
    rep(i, n) {
        rep(b, 10) {
            DP[i + 1][b] = DP[i][b];
            Pi[i + 1][b] = {i, b};
        }
        rep(b, 10) {
            if(DP[i + 1][(b * A[i]) % 10] <= DP[i][b] + Calc[i]) {
                DP[i + 1][(b * A[i]) % 10] = DP[i][b] + Calc[i];
                Pi[i + 1][(b * A[i]) % 10] = {i, b};
            }
        }
    }
    ll dpn = n, dpd = d;
    if(DP[n][d] < 0) {
        cout<<"-1\n";
        return 0;
    }
    
    // cout<<DP[n][d]<<'\n';
    vl Ans;
    while(dpn > 0) {
        auto [_, b] = Pi[dpn][dpd];
        // cout<<"paso del digito "<<dpd<<" a "<<b<<'\n';
        if(abs(DP[dpn][dpd] - DP[dpn - 1][b]) > 0.5) {
            Ans.pb(A[dpn - 1]);
        }
        if(A[dpn - 1] == 1) Ans.pb(1);
        dpn--, dpd = b;
    }
    if(Ans.size() == 0) {
        cout<<"-1\n";
    }
    else {
        cout<<Ans.size()<<'\n';
        for(auto u: Ans) cout<<u<<' '; cout<<'\n';
    }

    return 0;
}