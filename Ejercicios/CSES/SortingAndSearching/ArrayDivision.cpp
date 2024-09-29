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

// holas

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin>>n>>k;
    ll A[n]; rep(i, n) cin>>A[i];
    
    ll l = 0, r = 1e15;
    rep(i, n) l = max(l, A[i]);
    while(l < r) {
        ll cont = 1, suma = 0;
        ll m = (l + r) / 2;
        rep(i, n) {
            if(suma + A[i] > m) {
                suma = A[i];
                cont++;
            }
            else suma += A[i];
        }
        // cout<<l<<' '<<r<<' '<<m<<", "<<cont<<' '<<k<<'\n';
        if(cont <= k) r = m;
        else l = m + 1;
    }
    cout<<l<<'\n';

    return 0;
}