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

struct Comp {
    bool operator()(array<ll, 3> a, array<ll, 3> b) {
        return a[0] > b[0];
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, k; cin>>n>>k;
    ll A[n], B[n];
    ll death = 0;
    multiset<array<ll, 2>> S; // [vida, indice]
    rep(i, n) cin>>A[i];
    rep(i, n) {
        cin>>B[i];        
        S.insert({A[i] / B[i], i});
    }

    ll cont = 0;
    bool imp = 0;
    for(auto [vida, indice]: S) {
        cont++;
        if(vida + 1 < cont) imp = 1;
    }
    if(imp) {
        cout<<"-1\n";
        return 0;
    }

    ll l = 0, r = 2e12+5;
    while(l < r) {
        ll m = (l + r) / 2;
        // multiset<array<ll, 3>> S2;
        priority_queue<array<ll, 3>, vector<array<ll, 3>>, Comp> S3;
        // rep(i, n) S2.insert({A[i] / B[i], A[i], i});
        rep(i, n) S3.push({A[i] / B[i], A[i], i});
        bool pos = 1;
        rep(i, k) {
            // auto [etapas, vida, ind] = *S2.begin();
            auto [etapas, vida, ind] = S3.top(); S3.pop();
            if(etapas < i) {
                pos = 0;
                break;
            }
            // S2.erase(*S2.begin());
            vida += m;
            // S2.insert({vida / B[ind], vida, ind});
            S3.push({vida / B[ind], vida, ind});
        }

        if(pos == 1) r = m;
        else l = m + 1;
    }
    cout<<l<<'\n';


    return 0;
}