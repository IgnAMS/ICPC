#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> pll;
typedef double db;
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt


const int mxN = 5e5+5;
const db EPS = 1e-12;

ll X[mxN], V[mxN];

int n;
const db INF = 1e9+0.0005;

bool intersect(db t) {
    db mx = -INF;
    bool on = 0;
    rep(i, n) {
        if(on and V[i] < 0 and X[i] + t * V[i] <= mx) return 1; 
        if(V[i] > 0) {
            mx = max(mx, X[i] + t * V[i]);  
            on = 1;
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    
    rep(i, n) cin>>X[i]>>V[i];
    
    bool right = 0;
    bool inter = 0;
    rep(i, n) {
        if(V[i] > 0) right = 1;
        if(V[i] < 0 and right) inter = 1;
    }
    if(!inter) {
        cout<<"-1\n";
        return 0;
    }
    
    db l = 0, r = INF;
    rep(_, 60) {
        db m = (l + r) / 2;
        if(intersect(m)) r = m;
        else l = m;
    }
    cout<<setprecision(14)<<fixed<<(l + r) * 0.5<<'\n';
    
    return 0;
}