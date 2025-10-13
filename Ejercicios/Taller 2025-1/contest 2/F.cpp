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
    vl A(n); rep(i, n) cin>>A[i];
    vl B(m); rep(i, m) cin>>B[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());


    ll l = 0, r = 1e10;
    while(l < r) {
        ll mid = (l + r) / 2;
        vector<pll> E;
        rep(i, n) E.pb({A[i], 1});
        rep(i, m) {
            E.pb({B[i] - mid, 0});
            E.pb({B[i] + mid, 2});
        }
        sort(E.begin(), E.end());

        ll cont = 0;
        bool pos = 1;
        for(auto e: E) {
            if(e.ss == 0) cont++;
            if(e.ss == 1 and cont == 0) pos = 0;
            if(e.ss == 2) cont--; 
        }
        if(pos) r = mid;
        else l = mid + 1;
    }
    cout<<l<<'\n';

    return 0;
}