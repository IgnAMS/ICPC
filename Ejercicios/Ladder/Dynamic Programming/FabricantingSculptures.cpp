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

ll DP[5001][5001]; // 2 * 10^7
ll MOD = 1e9 + 7;


ll dp(ll s, ll b) {
    if(s <= 0 or b < 0) return 0;
    if(b == 0 or s == 1) return 1;
    if(DP[s][b] != -1) return DP[s][b];
    return DP[s][b] = (dp(s, b - s) + 2 * dp(s - 1, b) - dp(s - 2, b) + MOD) % MOD;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int s, b; cin>>s>>b;
    memset(DP, -1, sizeof DP);
    cout<<dp(s, b - s)<<'\n';




    return 0;
}