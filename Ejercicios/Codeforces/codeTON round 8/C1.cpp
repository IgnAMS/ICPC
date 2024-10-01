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
    int t; cin>>t;
    while(t--) {
        int n, x, y; cin>>n>>x>>y;

        vl X(x);
        rep(i, x) {
            cin>>X[i];
        }
        sort(X.begin(), X.end());
        ll mn = X[0];
        rep(i, x) X[i] -= mn;
        
        if(x == n) {
            cout<<n - 2<<'\n';
            continue;
        }

        ll ans = x - 2;
        ll cont = 0;
        repx(i, 1, x + 1) {
            if(X[i % x] == (X[i - 1] + 2) % n) ans++;
        }
        cout<<ans<<'\n';
    }

    return 0;
}