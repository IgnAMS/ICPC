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
ll DP[100005][2];
ll R[100005];
ll dp(int x, bool tomado){
    if(x == -1) return 0;
    if(DP[x][tomado] != -1) return DP[x][tomado];
    if(tomado) DP[x][tomado] = dp(x - 1, 0);
    else DP[x][tomado] = max(dp(x - 1, 1) + R[x], dp(x-1, 0));
    // cerr<<"DP["<<x<<","<<tomado<<"]: "<<DP[x][tomado]<<'\n';
    return DP[x][tomado];
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int m, n;
    while(cin>>m>>n and m){
        vector<int> rows;
        rep(i, m){
            int imp = 0, par = 0;
            rep(j, n) cin>>R[j];
            int maxi = 0; bool tomado = 0;
            rep(i, n+1) DP[i][0] = -1, DP[i][1] = -1;
            // cerr<<n<<'\n';
            rows.push_back(dp(n-1, 0));
            // cout<<rows.back()<<'\n';
        }
        rep(i, m+1) DP[i][0] = -1, DP[i][1] = -1;
        rep(i, m) R[i] = rows[i];
        cout<<dp(m-1, 0)<<'\n';
    }

    return 0;
}