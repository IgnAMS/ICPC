#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef double db;
#define repx(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) repx(i, 0, n)
#define pb push_back


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    set<ll> S;
    for(int d = 1; d * d <= n; d++) {
        if(n % d == 0) {
            bool oc = 1;
            for(int j = 2 * d; j < n; j += d) if(n % j == 0) oc = 0;
            if(oc) S.insert(d);

            bool oc2 = 1;
            ll x = n / d;
            if(x == n) continue;
            for(int j = 2 * x; j < n; j += x) if(n % j == 0) oc2 = 0;
            if(oc2) S.insert(n / d);
        }
    }

    cout<<S.size()<<'\n';
    for(auto d: S) {
        cout<<1<<" "<<d<<'\n';
    }



    return 0;
}

