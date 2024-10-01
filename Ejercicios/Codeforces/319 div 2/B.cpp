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

bool solve(vl B, ll m) {
    vl V(m, 0);
    if(B[0]) return 1;
    repx(i, 1, m) {
        if(B[i] >= m) return 1;
        if(B[i] >= m / __gcd(i, int(m))) return 1;
    }
    // n * m
    rep(i, m) {
        vl V2(m, 0);
        rep(k, m) if(V[k]) {
            repx(j, 1, B[i] + 1) { //[1, B[i]]
                V2[(k + i * j) % m] = 1;
                if((k + i * j) % m == 0) return 1; 
            }
        }
        repx(j, 1, B[i] + 1) V2[(i * j) % m] = 1;
        rep(i, m) V[i] |= V2[i];
    }
    return V[0];
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    ll A[n]; rep(i, n) cin>>A[i];
    vl B(m, 0); 
    rep(i, n) B[A[i] % m]++;
    cout<<(solve(B, m)? "YES": "NO")<<'\n';




    return 0;
}