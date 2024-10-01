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
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vl V(n + 1, 0);
        vl A;
        repx(i, 1, n + 1) {
            if(V[i]) continue;
            ll u = i;
            while(u <= n) {
                A.pb(u);
                V[u] = 1;
                u = 2 * u;
            }
        }
        repx(i, 1, n + 1) {
            if(!V[i]) A.pb(i);
        }
        rep(i, n) cout<<A[i]<<' '; cout<<'\n';
    }


    return 0;
}