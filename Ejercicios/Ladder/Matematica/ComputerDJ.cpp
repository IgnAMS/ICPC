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
    int n, q; 
    while(cin>>n>>q and n) {
        vector<string> A(n);
        rep(i, n) cin>>A[i];
        rep(_, q) {
            ll x; cin>>x;
            ll d = 1, npot = n;
            while(x > d * npot) {
                x -= d * npot;
                npot *= n;
                d++;
            }
            // cerr<<x<<' '<<d<<' '<<npot<<'\n';
            ll auxx = x;
            x--;
            vl B(d);
            rep(i, d) {
                // cerr<<x<<' '<<npot<<'\n';
                npot /= n;
                B[i] = x / (npot * d);
                x -= B[i] * npot * d;
            }
            // rep(i, d) cout<<B[i]<<' '; cout<<'\n';
            cout<<A[B[(auxx - 1) % d]]<<'\n';
        }
        cout<<'\n';
    }


    return 0;
}