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
    int n; cin>>n;
    vl A(n); rep(i, n) cin>>A[i];
    int m; cin>>m;
    rep(caso, m) {
        // 100 
        int k, pos; cin>>k>>pos;
        set<pll> S;
        vl V(n, 1);
        rep(i, n) S.insert({A[i], -i});
        rep(xd, n - k) {
            auto [u, d] = *S.begin();
            S.erase(S.begin());
            V[-d] = 0;
        }
        ll cont = 0;
        rep(i, n) {
            cont += V[i];
            if(cont == pos) {
                cout<<A[i]<<'\n';
                break;
            }
        }
    }





    return 0;
}