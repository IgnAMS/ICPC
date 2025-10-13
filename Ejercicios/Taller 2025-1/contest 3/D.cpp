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
    int n; cin>>n;
    vl P(n), A(n), B(n);
    rep(i, n) cin>>P[i];
    rep(i, n) cin>>A[i];
    rep(i, n) cin>>B[i];

    set<pll> S1[4], S2[4];
    rep(i, n) {
        S1[A[i]].insert({P[i], i});
        S2[B[i]].insert({P[i], i});
    }

    int m; cin>>m;
    rep(i, m) {
        int x; cin>>x;
        if(S1[x].empty() and S2[x].empty()) cout<<"-1 ";
        else if(S1[x].empty()) {
            auto [p, id] = *S2[x].begin();
            S1[A[id]].erase({p, id});
            S2[x].erase(*S2[x].begin());
            cout<<p<<' ';
        }
        else if(S2[x].empty()) {
            auto [p, id] = *S1[x].begin();
            S1[x].erase(*S1[x].begin());
            S2[B[id]].erase({p, id});
            cout<<p<<' ';
        }
        else if(S1[x].begin()->ff <= S2[x].begin()->ff) {
            auto [p, id] = *S1[x].begin();
            S1[x].erase(*S1[x].begin());
            S2[B[id]].erase({p, id});
            cout<<p<<' ';
        }
        else {
            auto [p, id] = *S2[x].begin();
            S1[A[id]].erase({p, id});
            S2[x].erase(*S2[x].begin());
            cout<<p<<' ';
        } 
    } 
    cout<<'\n';



    return 0;
}