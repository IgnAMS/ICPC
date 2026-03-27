#pragma GCC optimize("Ofast")
#include<string.h>
#include<vector>
#include<map>
#include<deque>
#include<queue>
#include<iostream>
#include <algorithm>
#include<set>
#include<array>
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
// g++ -std=c++17 A.cpp -o a && ./a <input.txt> output.txt   
// ulimit -s 1000000
// g++ -O2 F.cpp && time ./a.out <input.txt> output.txt

void solve() {
    int n; cin>>n;
    cout<<n<<"\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        solve();
    }
    int n = 100000;
    ll F[n];
    F[0] = 0, F[1] = 1;
    repx(i, 2, n) {
        F[i] = (F[i-1] + F[i-2]) % 10000000000LL;
    }
    
    rep(d, 10) {
        map<int, vl> mp;
        rep(i, 10) mp[i] = {};

        rep(i, n) mp[F[i] % 10].pb(i);

        cout<<"ciclos del digito "<<d<<"\n";
        rep(i, 10) {
            vl ind;
            rep(j, mp[i].size() - 1) cout<<mp[i][j+1] - mp[i][j]<<", "; cout<<"\n";
        }
        rep(i, n) F[i] /= 10;
        cout<<"\n\n";
    }
    
    
    

    return 0;
}