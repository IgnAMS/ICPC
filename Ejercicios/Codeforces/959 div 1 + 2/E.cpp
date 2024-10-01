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



const ll INF = 1e10;
int mxN = 1e6 + 5;


// 30 * mxN ~ 3 * 10^7

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        int k; cin>>k;
        ll total_size = 0;
        vector<vl> P(k, vl());
        vector<vector<vl>> G(k, vector<vl>());
        vl sz(k);
        rep(i, k) {
            ll size ; cin>>size;
            sz[i] = size;
            total_size += size;
            G[i].assign(size, vl());
            P[i].resize(size);
            rep(j, size - 1) {
                cin>>P[i][j]; P[i][j]--;
                G[i][P[i][j]].pb(j + 1);
            }
        }
        vl B(21, 0);
        for(int b = 20; b >= 0; b--) {
            rep(i, k) {
                if(sz[i] & (1<<b)) B[b]++;
            }
        }

        ll ans = 0;
        ll init = 0;
        for(int b = 20; b >= 0; b--) {
            if(B[b] == 1) ans += (1<<b);
            else if(B[b] >= 2) ans += (1<<b), init = 1;
            else if(init) ans += (1<<b); 
        }
        cout<<ans<<'\n';

    }


    return 0;
}