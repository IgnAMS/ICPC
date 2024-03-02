#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(long long i=a; i<b; i++)
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


bool DP[32][32][32][99][99];
bool V[32][32][32][99][99];
ll A[34];
ll total;

bool dp(int d1, int d2, int d3, int sum1, int sum2) {
    if(d1 == 0 and d2 == 0 and d3 == 0 and sum1 == 0 and sum2 == 0) return 1;
    if(d1 < 0 or d2 < 0 or d3 < 0) return 0;
    if(sum1 < 0 or sum2 < 0) return 0;
    
    auto& ans = DP[d1][d2][d3][sum1][sum2];
    if(V[d1][d2][d3][sum1][sum2]) return ans;
    V[d1][d2][d3][sum1][sum2] = 1;

    ll ind = d1 + d2 + d3 - 1;
    ans = 0;
    if(d1 and dp(d1 - 1, d2, d3, sum1 - A[ind], sum2)) ans = 1;
    if(d2 and dp(d1, d2 - 1, d3, sum1, sum2 - A[ind])) ans = 1;
    if(d3 and dp(d1, d2, d3 - 1, sum1, sum2)) ans = 1;
    return ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin>>n>>k;
    total = 0;
    rep(i, n) {
        cin>>A[i];
        total += A[i];
    }
    rep(a, n - 1) rep(b, n - 1) rep(c, n - 1) rep(sum1, total - 1) rep(sum2, total - 1) V[a][b][c][sum1][sum2] = 0;
    ll num = 1e11, div = 1;
    repx(a, 1, n - 1) repx(b, a, n - 1) repx(c, b, n - 1) if(a + b + c == n) rep(sum1, total - 1) rep(sum2, total - 1) {
        if(dp(a, b, c, sum1, sum2)) {
            ll newnum = sum1 * b * c + sum2 * a * c + (total - sum1 - sum2) * a * b;
            ll newdiv = a * b * c * 3;
            ll g = __gcd(newnum, newdiv);
            newnum /= g;
            newdiv /= g;
            ll newcost = abs(k * newdiv - newnum);
            ll oldcost = abs(k * div - num);
            if(newcost * div < oldcost * newdiv) {
                // cerr<<"actualice con "<<a<<' '<<b<<' '<<c<<' '<<sum1<<' '<<sum2<<'\n';
                num = newnum, div = newdiv;
            }
        }
    }
    cout<<num<<"/"<<div<<'\n';



    return 0;
}