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

ll a, b, c, d; 
bool inrect(ll x, ll y) {
    if(a <= x and x <= c and b <= y and y <= d) return 1;
    return 0;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll x, y; cin>>x>>y;
    cin>>a>>b>>c>>d;
    ll g = __gcd(x, y);
    pll d = {x / g, y / g};
    if(g == 1) {
        cout<<"Yes\n";
        return 0;
    }
    if(inrect(d.ff, d.ss) and inrect(x - d.ff, y - d.ss)) {
        cout<<"Yes\n";
    }
    else {
        cout<<"No\n";
        if(!inrect(d.ff, d.ss)) {
            cout<<d.ff<<' '<<d.ss<<'\n';
        }
        else {
            ll l = 0, r = (1e13 + d.ss - 1) / d.ss;
            while(l < r) {
                ll m = (l + r) / 2;
                if(inrect(d.ff * m, d.ss * m)) l = m + 1;
                else r = m; 
            }
            cout<<d.ff * l<<' '<<d.ss * l<<'\n';
        } 
    }
    

    return 0;
}