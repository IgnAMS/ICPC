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
    int n, h; cin>>n>>h;
    ll A[n]; rep(i, n) cin>>A[i];
    ll l = 0, r = n;
    while(l < r) {
        int m = (l + r + 1) / 2;
        vl B; 
        rep(i, m) B.pb(A[i]);
        sort(B.begin(), B.end());
        
        ll acc = 0;
        for(int i = m - 1; i >= 0; i -= 2) {
            // cout<<"aumento en "<<B[i]<<'\n';
            acc += B[i];
        }
        // cout<<l<<' '<<r<<'\n';
        // cout<<m<<'\n';
        // for(auto u: B) cout<<u<<' '; cout<<'\n';
        // cout<<"acc: "<<acc<<'\n';

        if(acc <= h) l = m;
        else r = m - 1;
    }
    cout<<l<<'\n';



    return 0;
}