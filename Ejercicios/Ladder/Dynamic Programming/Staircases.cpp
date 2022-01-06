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

ll DP[505][505];

ll dp(int n, int h){
    if(DP[n][h] != -1) return DP[n][h];
    if(n < 3) return 0; 
    DP[n][h] = 0;
    repx(i, 1, min(n, h)){ 
        if(n - i > i and n - i < h) DP[n][h] += 1;
    }
    repx(k, 1, h){
        if(n - k < 0) break;
        DP[n][h] += dp(n - k, k);
    }
    // cerr<<"DP["<<n<<','<<h<<"]: "<<DP[n][h]<<'\n';
    return DP[n][h];
}




int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    memset(DP, -1, sizeof DP);
    int n; cin>>n;
    cout<<dp(n, n)<<'\n';





    return 0;
}