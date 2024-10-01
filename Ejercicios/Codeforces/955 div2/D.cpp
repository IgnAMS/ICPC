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
    int t; cin>>t;

    while(t--) {
        ll n, m, k; cin>>n>>m>>k;
        ll A[n][m]; rep(i, n) rep(j, m) cin>>A[i][j];
        string Col[n]; rep(i, n) cin>>Col[i];
        
        vector<vl> S(n, vl(m, 0));
        ll dif = 0;
        ll Acc[n + 1][m + 1];
        rep(i, n) rep(j, m) {
            dif += (Col[i][j] == '1'? 1LL: -1LL) * A[i][j];
            Acc[i + 1][j + 1] = Acc[i][j + 1] + Acc[i + 1][j] - Acc[i][j] + (Col[i][j] == '1'? 1: -1);
        }
        // cout<<"dif: "<<dif<<'\n';
        

        set<ll> Nonzero;
        // rep(i, n - k + 1) rep(j, m - k + 1) {
        //     // cout<<Acc[i + k][j + k] - Acc[i + k][j] - Acc[i][j + k] + Acc[i][j]<<'\n'; 
        //     // repx(di, i, i + k) repx(dj, j, j + k) {
        //     //     S[i][j] += (Col[di][dj] == '1'? 1LL: -1LL);
        //     // }
        // }

        rep(i, n - k + 1) {
            rep(j, m - k + 1) {
                // cout<<S[i][j]<<' ';
                // if(S[i][j] != 0) Nonzero.insert(abs(S[i][j]));
                ll val = Acc[i + k][j + k] - Acc[i + k][j] - Acc[i][j + k] + Acc[i][j]; 
                if(val != 0) Nonzero.insert(abs(val));
            }
            // cout<<'\n';
        }

        if(dif == 0) cout<<"YES\n";
        else if(Nonzero.size() == 0) cout<<"NO\n";
        else if(Nonzero.size() >= 1) {
            ll g = *Nonzero.begin();
            for(auto u: Nonzero) g = __gcd(g, u);
            if(abs(dif) % g == 0)  cout<<"YES\n";
            else cout<<"NO\n";
        }
        else cout<<"NO\n";

    }





    return 0;
}