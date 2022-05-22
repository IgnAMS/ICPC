#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt

vi C;
ll DP[500][500];

// k es en la moneda que voy, x es lo que me queda
ll dp(int k, int x) {  
    if(DP[k][x] != -1) return DP[k][x];
    if(x == 0 and k == C.size()) {
        // cerr<<"entre en este caso\n";
        return 1;
    }
    if(k == C.size()) return 0;
    // cerr<<"analizo "<<k<<' '<<x<<'\n';
    DP[k][x] = 0;
    rep(i, x / C[k] + 1) {
        DP[k][x] += dp(k + 1, x - i * C[k]);
    }
    return DP[k][x];
}




int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin>>n>>k;
    C.assign(k, 0); rep(i, k) cin>>C[i];
    memset(DP, -1, sizeof DP);
    cout<<dp(0, n)<<'\n';






    return 0;
}