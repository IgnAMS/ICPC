#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") // could make sigill runtime error
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=(int)a; i<(int)b; i++)
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
    vl DP(1000005, 0);
    // cerr<<n<<'\n';
    const ll MOD = 1e9+7;

    repx(i, 1, n + 1) {
        DP[i] = (i <= 6);
        repx(d, 1, 7) if(i - d >= 0) {
            DP[i] += DP[i - d];
            if(DP[i] >= MOD) DP[i] -= MOD;
        }
    }
    cout<<DP[n]<<'\n';


    return 0;
}