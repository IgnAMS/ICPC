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


const db PI = acos(-1.0);

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    db ang;
    int n; cin>>ang>>n;
    vector<pll> X(n);
    rep(i, n) {
        cin>>X[i].ff>>X[i].ss;
    }
    sort(X.begin(), X.end());

    db left = X[0].ff, right = X[0].ff;
    db ans = 0;
    ang = ang * PI / 180.0;
    rep(i, n) {
        if(X[i].ff > right) { 
            ans += right - left;
            left = X[i].ff;
        }
        right = max(right, X[i].ff + X[i].ss / tan(ang));
    }
    ans += right - left;
    cout<<setprecision(6)<<fixed<<ans<<'\n';




    return 0;
}