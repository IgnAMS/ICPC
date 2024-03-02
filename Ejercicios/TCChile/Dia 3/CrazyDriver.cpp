#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") // could make sigill runtime error
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
    int n; cin>>n;
    vl C(n - 1); rep(i, n - 1) cin>>C[i];
    vl T(n); rep(i, n) cin>>T[i];
    
    // rep(i, n - 1) cout<<R[i]<<' '; cout<<'\n';
    
    ll t = 0, ans = 0;
    ll mn = C[0];
    rep(i, n - 1){
        mn = min(C[i], mn);
        if(t + 1 < T[i + 1]) {
            ll aux = (T[i + 1] - t) / 2 * 2;
            t += aux + 1;
            ans += aux * mn + C[i];            
        }
        else t++, ans += C[i];

    }
    cout<<ans<<'\n';

    return 0;
}