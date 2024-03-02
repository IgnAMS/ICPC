#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> pll;
typedef double db;
typedef vector<int> vl;
#define ff first
#define ss second
#define pb push_back
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

const int mxN = 1e6+2;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int lpf[mxN], mob[mxN];
    rep(i, mxN) lpf[i] = 0;
    for(int i = 2; i <= 1e6; i++) if(!lpf[i]) {
        for(int j = i; j <= 1e6; j += i) {
            if(!lpf[j]) lpf[j] = i;
        }
    }
    
    for(int i = 1; i <= 1e6; i++) {
        if(i == 1) mob[i] = 1; 
        else {
            if(lpf[i / lpf[i]] == lpf[i]) mob[i] = 0;
            else mob[i] = -1 * mob[i / lpf[i]];
        }
    }
    
    
    ll n; cin>>n;
    vl A(n), S(1e6+3, 0);
    rep(i, n) {
        cin>>A[i];
        S[A[i]]++;
    }
    
    ll ans = 0;
    repx(i, 1, 1e6+1) {
        ll d = 0;
        for(ll j = i; j <= 1e6; j += i) d += S[j];
        ans += (d * (d - 1) / 2) * mob[i];
    }
    
    cout<<ans<<'\n';

    return 0;
}