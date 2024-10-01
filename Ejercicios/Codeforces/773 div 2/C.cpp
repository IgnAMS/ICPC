#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
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
        ll n, x; cin>>n>>x;
        vi A(n); rep(i, n) cin>>A[i];
        map<ll, ll> mapa;
        rep(i,n) {
            if(!mapa.count(A[i])) mapa[A[i]] = 0;
            mapa[A[i]]++;
        }
        for(auto& u: mapa) {
            while(u.ss > 0 and mapa.count(u.ff * x) and mapa[u.ff * x] > 0) u.ss--, mapa[x * u.ff]--;
        }
        ll ans = 0;
        for(auto u: mapa) ans += u.ss;
        cout<<ans<<'\n';

    }





    return 0;
}