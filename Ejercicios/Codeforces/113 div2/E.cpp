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


const ll MOD = 1e9+7;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    ll DP[4][2];
    rep(i, 4) rep(b, 2) DP[i][b] = 0;
    DP[3][0] = 1;
    rep(_, n) {
        rep(i, 4) {
            DP[i][1] = 0;
            rep(j, 4) if(j != i) {
                DP[i][1] += DP[j][0];
                if(DP[i][1] >= MOD) DP[i][1] -= MOD;
            }
        }
        rep(i, 4) DP[i][0] = DP[i][1], DP[i][1] = 0;
    }
    cout<<DP[3][0]<<'\n';

    return 0;
}