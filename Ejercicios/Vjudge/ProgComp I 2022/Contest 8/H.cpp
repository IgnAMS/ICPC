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
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin>>n;
    vi C(n), T(n);
    rep(i, n - 1) cin>>C[i];
    rep(i, n) cin>>T[i];
    ll t = 0;
    ll mn = C[0];
    ll ans = 0;
    rep(i, n - 1) {
        mn = min(C[i], mn);
        if(t + 1 < T[i + 1]) {
            ll aux = (T[i + 1] - t) / 2 * 2;
            t += aux + 1;
            ans += aux * mn + C[i];
            // cout<<"Hago "<<aux / 2<<" ciclos en "<<i<<'\n';
        }
        else t++, ans += C[i];
    }
    cout<<ans<<'\n';


    return 0;
}