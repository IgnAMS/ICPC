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

const int mxK = 5005;
const int mxN = 1e6+5;
ll M = 1e9+7;
ll F[mxN], Acc[mxK], A[mxK];
ll P[mxK][mxK], Z[mxK][mxK];

ll n, k, total;

ll getZ(ll i, ll j);

ll getP(ll i, ll j) {
    if(j == 0) {
        return F[Acc[i]];
    }
    if(P[i][j] != -1) return P[i][j];

    P[i][j] = F[Acc[i]];
    repx(k, 1, j + 1) {
        P[i][j] -= getZ(i, k);
        if(P[i][j] < 0) P[i][j] += M;
    }
    return P[i][j];
}

// Z(i, j) is the number of bad permutations such that is only bad for j
ll getZ(ll i, ll j) {
    if(Z[i][j] != -1) return Z[i][j];
    Z[i][j] = F[Acc[i] - Acc[j]] * getP(j,  j - 1) % M;
    return Z[i][j];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    total = 0;
    rep(i, k) {
        cin>>A[i];
        total += A[i];
    }

    Acc[0] = 0;
    rep(i, k) Acc[i + 1] = Acc[i] + A[i];
    Acc[k + 1] = n;
    
    // rep(i, k + 2) cout<<Acc[i]<<' '; cout<<'\n';
    
    F[0] = 1;
    rep(i, mxN - 1) F[i + 1] = (F[i] * ll(i + 1)) % M;

    rep(i, mxK) rep(j, mxK) P[i][j] = Z[i][j] = -1;

    cout<<getP(k + 1, k)<<'\n';

    return 0;
}