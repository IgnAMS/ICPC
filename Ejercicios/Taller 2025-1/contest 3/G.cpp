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
    string s; cin>>s;
    ll A[n]; rep(i, n) cin>>A[i];
    ll L[n], R[n];
    rep(i, n) L[i] = i - 1, R[i] = i + 1;

    set<pll> S;
    rep(i, n - 1) {
        if(s[i] != s[i + 1]) S.insert({abs(A[i] - A[i + 1]), i});
    }

    vector<pll> Ans;
    while(!S.empty()) {
        // for(auto u: S) cout<<"("<<u.ff<<' '<<u.ss<<"), "; cout<<'\n';
        auto [x, id] = *S.begin();
        S.erase({x, id});
        ll l = L[id], r = R[R[id]];
        Ans.pb({id + 1, R[id] + 1});
        // cout<<id + 1<<' '<<R[id] + 1<<'\n';
        if(l != -1) R[l] = r;
        if(r != n) L[r] = l;

        if(r != n and S.count({abs(A[R[id]] - A[r]), R[id]})) S.erase({abs(A[R[id]] - A[r]), R[id]});
        if(l != -1 and S.count({abs(A[id] - A[l]), l})) S.erase({abs(A[id] - A[l]), l});
        if(l != -1 and r != n and s[l] != s[r]) {
            S.insert({abs(A[l] - A[r]), l});
        }
    }
    cout<<Ans.size()<<'\n';
    for(auto [a, b]: Ans) cout<<a<<' '<<b<<'\n';




    return 0;
}