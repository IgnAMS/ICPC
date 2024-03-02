#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;

#define repx(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) repx(i, 0, n)

const int mxN = 1e6+3;
ll mod = 1e9+7;



int main() {
    int n; cin>>n;
    ll X[n]; rep(i, n) cin>>X[i];
    set<ll> S; 
    int j = 0;
    rep(i, 2000001) {
        if(X[j] == i) {
            j++;
            continue;
        }
        S.insert(i);
    }
    int q; cin>>q;
    while(q--) {
        int ind; cin>>ind; ind--;
        auto it = S.lower_bound(X[ind]);
        cout<<*it<<'\n';
        ll aux = X[ind]; X[ind] = *it;
        S.erase(it);
        S.insert(aux);
    }





    return 0;
}