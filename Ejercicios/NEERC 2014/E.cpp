#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
#define ff first
#define ss second
#define repx(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define rep(i, n) repx(i, 0, n)
#define pb push_back

bool mergeable(pll a, pll b) {
    ll wins = (a.ff > a.ss) + (b.ff > b.ss);
    ll merge = (a.ff + b.ff > a.ss + b.ss);
    // Estas son las prohibidas
    // W x W -> W 
    // W x L -> Z 
    // W x L -> L
    return wins <= merge; 
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin>>n; 
    vector<pll> X(n);
    ll wins = 0;
    rep(i, n) {
        cin>>X[i].ff>>X[i].ss;
        wins += (X[i].ff > X[i].ss);
    }
    if(n <= 2 * wins - 1) {
        cout<<0<<'\n';
        return 0;
    }

    vl DP(n, 0);
    rep(i, n) {
        if(i == 0) DP[i] = 0;
        else if(i and mergeable(X[i], X[i - 1])) {
            DP[i] = max(DP[i - 1], (i >= 2? DP[i - 2]: 0LL) + 1);
        }
        else {
            DP[i] = DP[i - 1];
        }
        if(n - DP[i] == 2 * wins - 1) {
            cout<<DP[i]<<'\n';
            while(i > 0) {
                if(DP[i] == DP[i - 1]) {
                    i--;
                }
                else {
                    cout<<i<<' '<<i + 1<<'\n';
                    i -= 2;
                }
            }
            return 0;
        }
    }
    cout<<"-1\n";

}

