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
    ll P[n]; 
    rep(i, n) {
        cin>>P[i];
        P[i]--;
    }

    ll D[n + 1]; D[0] = 1;
    const ll MOD = 1e9 + 7;
    rep(i, n) {
        if(P[i] == i) D[i + 1] = D[i] + 2;
        else D[i + 1] = 2 * D[i] - D[P[i]] + 2;
        D[i + 1] = (D[i + 1] % MOD + MOD) % MOD;
     }
     cout<<D[n] - 1<<'\n';


    return 0;
}