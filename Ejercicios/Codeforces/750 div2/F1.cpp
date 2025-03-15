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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    ll A[n];
    const int mxA = 514;
    ll DP[mxA][2];
    rep(i, mxA) rep(b, 2) DP[i][b] = 1000000;
    DP[0][0] = 0;
    rep(i, n) {
        cin>>A[i];
        rep(j, mxA) {
            if((j ^ A[i]) < mxA and DP[j ^ A[i]][0] < A[i]) {
                DP[j][1] = min(DP[j][1], A[i]);
            }
        }
        // rep(j, 10) cout<<DP[j][1]<<' '; cout<<'\n';
        rep(j, mxA) DP[j][0] = min(DP[j][0], DP[j][1]);
    }

    set<ll> S;
    rep(j, mxA) if(DP[j][0] < 1000000) S.insert(j);
    cout<<S.size()<<'\n';
    for(auto u: S) cout<<u<<' '; cout<<'\n';


    return 0;
}