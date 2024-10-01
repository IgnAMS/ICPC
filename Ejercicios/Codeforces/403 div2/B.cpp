#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> pll;
typedef long double db;
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
    db X[n], V[n];
    rep(i, n) cin>>X[i];
    rep(i, n) cin>>V[i];

    db l = 0, r = 1e10;
    rep(_, 60) {
        db left_most = -1e17, right_most = 1e17; 
        db m = (l + r) * 0.5;
        rep(i, n) {
            left_most = max(left_most, X[i] - V[i] * m);
            right_most = min(right_most, X[i] + V[i] * m);
        }
        // cout<<m<<' '<<left_most<<' '<<right_most<<'\n';
        // rep(i, n) {
        //     cout<<X[i] - V[i] * m<<' '<< X[i] + V[i] * m<<'\n';
        // }
        // cout<<'\n';
        if(left_most <= right_most) r = m;
        else l = m;
    }
    cout<<setprecision(8)<<fixed<< (l + r) * 0.5<<'\n';





    return 0;
}