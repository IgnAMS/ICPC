#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef vector<ll> vl;

#define rep(i, n) for(int i = 0; i<(int)n; ++i)

ll DP[55][2];
ll A[55];
int n; 

ll dp(int i, int x) {
    if(i == n) 0;
    if(DP[i][x] != -100000000) return DP[i][x];
    cout<<"entre aca :D\n";
    if(x == 0) DP[i][x] = max(dp(i + 1, x ^ 1) + A[i], dp(i + 1, x) - A[i]);
    else DP[i][x] = min(dp(i + 1, x ^ 1) - A[i], dp(i + 1, x) + A[i]);
    return DP[i][x];
}

int main() {
    cin>>n;
    rep(i, n) cin>>A[i];
    memset(DP, -100000000, sizeof(DP));
    dp(0, 0);
    ll curr = 0;
    rep(i, n) {
        rep(x, 2) cout<<DP[i][x]<<' '; 
        cout<<'\n';
    }

    return 0;
}