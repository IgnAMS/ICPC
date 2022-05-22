#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(ll i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt


ll DP[502][502];

ll dp(ll x, ll h) {
    if(DP[x][h] != -1) return DP[x][h];
    if(x == 0) {
        return 1;
    }
    DP[x][h] = 0;
    repx(i, 1, min(x + (h != 501), h)) {
        DP[x][h] += dp(x - i, i);
    }
    return DP[x][h];
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;

    memset(DP, -1, sizeof DP);
    cout<<dp(n, 501)<<'\n';


    return 0;
}