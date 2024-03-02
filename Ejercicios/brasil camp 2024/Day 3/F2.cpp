#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") // could make sigill runtime error
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(ll i=a; i<b; i++)
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


ll INF = 1e17;
const int mxK = 5005;


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, k; cin>>n>>k;
    string s; cin>>s;
    vl A(28, 0); 
    rep(i, 28) A[s[i] - 'a']++;

    ll DP[mxK + 2][mxK + 2];
    ll newDP[mxK + 2][mxK + 2];

    rep(i, mxK) rep(j, mxK) DP[i][j] = -INF;
    rep(i, k + 1) DP[i][i] = 0;

    rep(i, 28) {
        rep(pos, mxK) rep(neg, mxK) newDP[pos][neg] = -INF;

        rep(pos, mxK) {
            rep(neg, mxK) {
                if(mxK - neg >= 5000) cout<<mxK - neg<<'\n';
                // neg + j <= k -> j <= k - neg
                rep(j, min(A[i], mxK - neg) + 1) {
                    newDP[i][j] = max(newDP[pos][neg], DP[pos][neg + j] + (A[i] - j) * (A[i] - j - 1) / 2LL * ll(i + 'a'));
                }
                
                // j + pos <= k
                // j <= k - pos
                if(mxK - pos >= 5000) cout<<mxK - pos<<'\n';
                rep(j, mxK - pos + 1) {
                    newDP[i][j] = max(newDP[pos][neg], DP[pos + j][neg] + (A[i] + j) * (A[i] + j - 1) / 2LL * ll(i + 'a'));
                }
            }
        }
        rep(pos, mxK) rep(neg, mxK) DP[pos][neg] = newDP[pos][neg];
    }
    cout<<DP[0][0]<<'\n'; 

    return 0;
}