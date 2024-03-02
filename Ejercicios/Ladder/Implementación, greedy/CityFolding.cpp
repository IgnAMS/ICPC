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
    ll n, p, h; cin>>n>>p>>h;
    vl A(n);
    ll aux = 1LL<<n;
    rep(i, n) {
        if(h > aux / 2) A[i] = 1, h = aux - h + 1;
        else A[i] = 0;
        aux /= 2;
    }
    reverse(A.begin(), A.end());
    // rep(i, n) cout<<A[i]<<' '; cout<<'\n';

    ll pos = p;
    aux = 1LL<<n;
    string ans;
    rep(i, n) {
        // cout<<pos<<' '<<A[i]<<'\n';
        if(A[i]) {
            if(pos <= aux / 2) ans += 'L', pos = aux / 2 - pos + 1; // Estoy en L y me movere arriba
            else ans += 'R', pos = aux - pos + 1; 
        }
        else {
            if(pos <= aux / 2) ans += 'R';
            else ans += 'L', pos = pos - aux / 2;
        }
        aux /= 2;
    }
    cout<<ans<<'\n';


    return 0;
}