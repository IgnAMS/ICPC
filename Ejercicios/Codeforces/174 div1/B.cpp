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

const int mxN = 2e5+5;
ll V[mxN][2];
ll C[mxN][2], A[mxN];
const ll INF = 1e15;
int n;
int cont = 0;
// retorno dos cosas
// 1: valor
// 2: si volvi a 0
ll dp(int u, bool b) {
    // cerr<<u<<' '<<b<<' '<<cont<<' '<<C[u][b]<<'\n';
    if(u < 0 or u >= n) return 0;
    
    if(u == 0 and b == 0) return INF;
    
    if(cont == C[u][b]) return INF;
    if(V[u][b] > 0) return V[u][b];

    C[u][b] = cont;
    V[u][b] = dp(u + (b? -A[u]: A[u]), !b) + A[u];

    return V[u][b];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    rep(i, n - 1) cin>>A[i + 1];
    rep(i, n - 1) {
        cont++;
        ll ans = dp(i + 1, 1);
        ans += i + 1;
        if(ans >= INF) {
            cout<<"-1\n";
            continue;
        }
        cout<<ans<<'\n';
    }


    return 0;
}