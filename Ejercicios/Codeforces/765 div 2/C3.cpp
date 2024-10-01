#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt

ll DP[501][501];
ll X[501], V[501];
ll n;
ll dp(int x, int k){
    if(x == n) return 0;
    if(DP[x][k] != -1) return DP[x][k];
    DP[x][k] = V[x] * (X[x+1] - X[x]) + dp(x+1, k);
    repx(i, 2, n-x+1){
        if(k - i + 1 >= 0) DP[x][k] = min(DP[x][k], V[x] * (X[x+i] - X[x]) + dp(x+i, k - i + 1));
    }
    return DP[x][k];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll l, k; cin>>n>>l>>k;
    rep(i, n) cin>>X[i]; X[n] = l;
    rep(i, n) cin>>V[i];
    memset(DP, -1, sizeof DP);
    cout<<dp(0, k)<<'\n';


    return 0;
}