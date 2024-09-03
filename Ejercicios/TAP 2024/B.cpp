#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef double db;
#define repx(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) repx(i, 0, n)
#define pb push_back

const ll mxN = 1e6+10;
vl Div[mxN];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i = 1; i < mxN; i++) {
        for(int j = 2 * i; j < mxN; j += i) {
            Div[j].pb(i);
        }
    }
    
    int n; cin>>n;
    set<ll> S;
    for(auto d: Div[n]) {
        bool oc = 1;
        for(int j = 2 * d; j < n; j += d) {
            if(n % j == 0) oc = 0;
        }
        if(oc) S.insert(d);
    }

    cout<<S.size()<<'\n';
    for(auto u: S) {
        cout<<1<<" "<<u<<'\n';
    }





    return 0;
}

