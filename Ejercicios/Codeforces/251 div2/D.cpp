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
    int n, m; cin>>n>>m;
    vl A(n), B(m);
    rep(i, n) cin>>A[i];
    rep(i, m) cin>>B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    vl AccA(n + 1, 0);
    rep(i, n) AccA[i + 1] = AccA[i] + A[i];
    vl AccB(m + 1, 0);
    rep(i, m) AccB[i + 1] = AccB[i] + B[i];

    ll ans = 1e15;
    rep(i, n) {
        ll inda = lower_bound(A.begin(), A.end(), A[i]) - A.begin();
        ll indb = lower_bound(B.begin(), B.end(), A[i]) - B.begin();
        // cout<<"hay "<<inda<<" elementos menores a "<<A[i]<<" en A\n";
        // cout<<A[i] * inda - AccA[inda]<<'\n';
        // cout<<"hay "<<m - indb<<" elementos mayores o iguales a "<<A[i]<<" en B\n";
        // cout<<AccB[m] - AccB[indb] - A[i] * (m - indb)<<'\n';
        // cout<<'\n';
        ans = min(
            ans, 
            (A[i] * inda - AccA[inda]) + (AccB[m] - AccB[indb] - A[i] * (m - indb))
        );
    }
    rep(i, m) {
        ll inda = lower_bound(A.begin(), A.end(), B[i]) - A.begin();
        ll indb = lower_bound(B.begin(), B.end(), B[i]) - B.begin();
        // cout<<"hay "<<inda<<" elementos menores a "<<B[i]<<" en A\n";
        // cout<<B[i] * inda - AccA[inda]<<'\n';
        // cout<<"hay "<<m - indb<<" elementos mayores o iguales a "<<B[i]<<" en B\n";
        // cout<<AccB[m] - AccB[indb] - B[i] * (m - indb)<<'\n';
        // cout<<'\n';
        ans = min(
            ans, 
            (B[i] * inda - AccA[inda]) + (AccB[m] - AccB[indb] - B[i] * (m - indb))
        );
    }
    cout<<ans<<'\n';





    return 0;
}