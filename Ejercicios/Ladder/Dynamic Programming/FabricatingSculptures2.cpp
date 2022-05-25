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
// g++ -std=c++11 FabricatingSculptures2.cpp -o a && a <input.txt> output.txt
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt


ll MOD = 1e9 + 7;
ll DP[5001][5001], Acc[5001][5001];


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int s, b; cin>>s>>b;
    memset(DP, 0, sizeof DP);
    memset(Acc, 0, sizeof Acc);
    rep(i, 5001) DP[0][i] = 0, DP[1][i] = 1, DP[i][0] = 1; DP[0][0] = 0;
    repx(i, 1, 5001) {
        repx(j, 1, 5001) {
            Acc[i][j] = (Acc[i - 1][j] + (j >= i? DP[i][j - i]: 0)) % MOD;
            DP[i][j] = (DP[i - 1][j] + Acc[i][j]) % MOD;
        }
    }
    // rep(i, 10) {
    //     cout<<"i: "<<i<<'\n';
    //     rep(j, 10) cout<<"j = "<<j<<": "<<DP[i][j]<<'\n'; cout<<"\n\n";
    // }

    cout<<DP[s][b - s]<<'\n';


    return 0;
}