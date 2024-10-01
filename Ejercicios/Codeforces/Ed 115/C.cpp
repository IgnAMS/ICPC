#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        ll n; cin>>n;
        vi A(n); rep(i, n) cin>>A[i];
        ll suma = 0; rep(i, n) suma += A[i];
        map<ll, vi> mp;
        rep(i, n) {
            if(!mp.count(A[i])) mp[A[i]] = {};
            mp[A[i]].push_back(i);
        } 
        ll ans = 0;
        for(auto& u: mp) sort(u.ss.begin(), u.ss.end());
        for(auto u: mp) if((suma * 2 - n * u.ff) % n == 0) {
            ll comp = (suma * 2 - n * u.ff) / n;
            if(!mp.count(comp)) continue;
            rep(i, u.ss.size()) {
                ans += (mp[comp].end() - upper_bound(mp[comp].begin(), mp[comp].end(), u.ss[i]));
            }
        }
        cout<<ans<<'\n';
    }



    return 0;
}