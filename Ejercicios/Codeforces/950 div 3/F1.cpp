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
        ll n, m, k; cin>>n>>m>>k;
        pll A[k];
        set<array<ll, 3>> S;
        rep(i, k) {
            cin>>A[i].ff>>A[i].ss;
            S.insert({A[i].ss, -A[i].ff, i});
        }
        
        vl V(k, 0);
        ll up = 0;
        ll prev = 1, ans = 0;
        for(auto [x, y, ind]: S) {
            y = -y;
            // if(x != prev) {
            //     cout<<"En "<<x<<' '<<y<<' '<<ind<<" aumento en "<<(x - prev)<<' '<<n - up<<'\n';
            // }
            ans += (x - prev) * (n - up);
            if(y > up) {    
                up = y;
                V[ind] = 1;
            }
            prev = x;
        }
        // cout<<"aumento "<<(m + 1 - prev)<<' '<<n - up<<'\n';
        ans += (m + 1 - prev) * (n - up);
        cout<<ans<<'\n';
        rep(i, k) cout<<V[i]<<' '; cout<<'\n';
    }


    return 0;
}