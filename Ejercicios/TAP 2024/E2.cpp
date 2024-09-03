#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef double db;
#define repx(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) repx(i, 0, n)
#define pb push_back
#define ff first
#define ss second

const int mxN = 1e5+10;
pair<ll, unordered_set<ll>> DP[mxN];

int n; 
ll P;
ll A[mxN], B[mxN], C[mxN];


pair<ll, unordered_set<ll>> dp(ll i) {
    if(DP[i].ff != -1) return DP[i];
    DP[i] = {0, {}};
    array<ll, 3> best;

    for(int j = 0; j < n; j++) if(i - B[j] >= 0) {
        auto [dmg, S] = dp((i - B[j]) / A[j]);
        if(S.count(j)) continue;

        if(dmg + C[j] > DP[i].ff) {
            DP[i].ff = dmg + C[j];
            DP[i].ss = S;
            DP[i].ss.insert(j);
            best = {A[j], B[j], C[j]};
        }
        else if(dmg + C[j] == DP[i].ff) {
            // Prioridad: el que tiene mayor A, si empatan, el que tiene mayor B, usar el de menor C en desempate
            if(best[0] < A[j]) { // Mayor A
                best = {A[j], B[j], C[j]};
                DP[i].ss = S;
                DP[i].ss.insert(j);
            }
            else if(best[0] == A[j] and best[1] < B[j]) { // Mayor B
                best = {A[j], B[j], C[j]};
                DP[i].ss = S;
                DP[i].ss.insert(j);
            }
            else if(best[0] == A[j] and best[1] == B[j] and best[2] > C[j]) { // Menor C
                best = {A[j], B[j], C[j]};
                DP[i].ss = S;
                DP[i].ss.insert(j);
            }
        }
    }
    return DP[i];
}



int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>P;
    rep(i, n) cin>>A[i]>>B[i]>>C[i];
    vector<array<ll, 3>> X;
    rep(i, n) X.pb({A[i], B[i], C[i]});
    sort(X.begin(), X.end(), [&](const array<ll, 3>& a, const array<ll, 3>& b) {
        if(a[0] != b[0]) return a[0] > b[0];
        if(a[1] != b[1]) return a[1] > b[1];
        return a[2] < b[2];
    });

    rep(i, n) {
        A[i] = X[i][0], B[i] = X[i][1], C[i] = X[i][2];
        // cout<<A[i]<<' '<<B[i]<<' '<<C[i]<<'\n';
    }
    // Inicializo la DP
    rep(i, P + 1) DP[i].ff = -1; 

    auto [dmg, S] = dp(P);
    cout<<dmg<<'\n';



    return 0;
}

