#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") // could make sigill runtime error
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
    ll R[n];
    db tot = 1;
    rep(i, n) {
        cin>>R[i];
        tot *= R[i];
    }
    db inv = 0, inv2 = 0; 
    rep(i, n) {
        repx(j, i + 1, n) {
            ll casos = 0;
            if(R[i] <= R[j]) {
                casos = R[i] * (R[i] - 1) / 2;
                inv2 += db(R[i] - 1) / db(2 * R[j]);
            }
            else {
                casos = R[j] * (R[j] - 1) / 2 + R[j] * (R[i] - R[j]);
                inv2 += db(R[j] - 1) / db(2 * R[i]) + 1. - db(R[j]) / db(R[i]);
            }
            inv += db(casos) / db(R[i] * R[j]);
            // inv2 += casos / db(R[i] * R[j]);
            // cout<<"el par "<<i<<' '<<j<<" tiene "<<casos<<" inversiones\n";
        }
    }
    cout<<fixed<<setprecision(6)<<inv2<<'\n';
    // cout<<setprecision(11)<<fixed<<inv2<<'\n';
    // cout<<setprecision(6)<<fixed<<inv / tot<<'\n';
    // cout<<setprecision(11)<<fixed<<inv / tot<<'\n';





    return 0;
}