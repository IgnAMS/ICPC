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
        int n, s1, s2; cin>>n>>s1>>s2;
        vector<pll> E(n);
        rep(i, n) {
            ll r; cin>>r;
            E[i] = {r, i};
        }
        sort(E.begin(), E.end(), greater<pll>());

        vl A, B;
        rep(i, n) {
            if((A.size() + 1) * s1 <= (B.size() + 1) * s2) {
                A.push_back(E[i].ss);
            }
            else {
                B.push_back(E[i].ss);
            }
        }

        cout<<A.size();
        for(auto u: A) cout<<' '<<u + 1; cout<<'\n';
        cout<<B.size();
        for(auto u: B) cout<<' '<<u + 1; cout<<'\n';

    }

    return 0;
}