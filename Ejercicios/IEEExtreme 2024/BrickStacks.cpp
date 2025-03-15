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
    ll n, x; cin>>n>>x;
    ll A[n]; rep(i, n) cin>>A[i];
    sort(A, A + n);
    ll l = 1, r = n;
    while(l < r) {
        int m = (l + r) / 2;
        bool pos = 1;
        rep(i, n) {
            if(i >= m and A[i - m] + x > A[i]) pos = 0;
        }
        if(pos) r = m;
        else l = m + 1;
    }
    // random

    cout<<l<<'\n';
    ll m = l;
    vl Ans[m];
    multiset<pll> S;
    bool pos = 1;
    rep(i, n) {
        if(S.size() < m) {
            Ans[S.size()].pb(A[i]);
            S.insert({A[i], S.size()});
        }
        else if(S.begin()->ff + x <= A[i]) {
            auto [val, ind] = *S.begin();
            S.erase(S.find(*S.begin()));
            S.insert({A[i], ind});
            Ans[ind].pb(A[i]);
        }
    }
    rep(i, m) {
        cout<<Ans[i].size()<<' ';
        for(int j = Ans[i].size() - 1; j >= 0; j--) {
            cout<<Ans[i][j]<<' ';
        }
        cout<<'\n';
    }

    return 0;
}