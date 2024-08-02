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


const int mxN = 1e5+5;
ll DP[mxN][2];
ll A[mxN][2];
int n;
ll dp(ll i, ll b) {
    if(i == n) return 0;
    if(DP[i][b] != -1) return DP[i][b];
    // cout<<"veo la mejor opcion entre\n";
    // cout<<A[i][b]<<" -> "<<A[i + 1][0]<<", "<<A[i][1 ^ b]<<" -> "<<A[i + 1][1]<<'\n';
    // cout<<A[i][b]<<" -> "<<A[i + 1][1]<<", "<<A[i][1 ^ b]<<" -> "<<A[i + 1][0]<<'\n';
    DP[i][b] = min(
        abs(A[i + 1][0] - A[i][b]) + abs(A[i + 1][1] - A[i][1 ^ b]) + dp(i + 1, 0),
        abs(A[i + 1][1] - A[i][b]) + abs(A[i + 1][0] - A[i][1 ^ b]) + dp(i + 1, 1)
    );
    return DP[i][b];
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    vl Cont(n + 1, 0);
    rep(i, 2 * n) {
        ll x; cin>>x;
        A[x][Cont[x]] = i;
        Cont[x]++;
    }
    rep(i, mxN) rep(b, 2) DP[i][b] = -1;
    A[0][0] = A[0][1] = 0;
    cout<<dp(0, 0)<<'\n';

    return 0;
}