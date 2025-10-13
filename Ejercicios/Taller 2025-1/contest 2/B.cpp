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
    int n; cin>>n;
    vl A(n);
    rep(i, n) cin>>A[i];
    sort(A.begin(), A.end());
    // for(auto u: A) cout<<u<<' '; cout<<'\n';
    // busqueda binaria sobre la cantidad de elementos que puedo eliminar
    ll l = 0, r = n / 2;
    while(l < r) {
        ll m = (l + r + 1) / 2;
        // reviso si puedo eliminar los primeros m elementos
        bool pos = 1;
        int j = m;
        rep(i, m) {
            while(j < n and A[j] < 2 * A[i]) j++;
            if(j == n) {
                pos = 0;
                break;
            }
            j++;
        }
        // cout<<l<<' '<<r<<' '<<m<<' '<<pos<<'\n';
        if(pos) l = m;
        else r = m - 1;
    }
    cout<<n - l<<'\n';

    return 0;
}